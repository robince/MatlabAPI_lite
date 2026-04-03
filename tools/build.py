#!/usr/bin/env python3

import argparse
import glob
import os
from pathlib import Path
import platform
import shlex
import subprocess
import sys


TEST_TYPEKINDS = [
    "real_c_double",
    "integer_c_int8_t",
    "integer_c_int16_t",
    "integer_c_int32_t",
    "integer_c_int64_t",
]
TEST_RANKS = list(range(0, 7))


def parse_args():
    parser = argparse.ArgumentParser(description="Build helper for MatlabAPI_lite")
    parser.add_argument(
        "action",
        choices=[
            "generate",
            "build-core",
            "build-tests",
            "build-all",
            "test",
            "clean",
        ],
    )
    parser.add_argument("--source-root", required=True)
    parser.add_argument("--process-templates", choices=["true", "false"], default="true")
    parser.add_argument("--pyf95pp-python", default="python")
    parser.add_argument("--pyf95pp-script", default="")
    parser.add_argument("--pyf95pp-pythonpath", default="")
    parser.add_argument("--mex-cmd", default="mex")
    parser.add_argument("--matlab-cmd", default="matlab")
    parser.add_argument("--large-array-dims", choices=["true", "false"], default="true")
    parser.add_argument("--debug-mex", choices=["true", "false"], default="false")
    parser.add_argument("--verbose-mex", choices=["true", "false"], default="false")
    parser.add_argument("--stamp", default="")
    return parser.parse_args()


def shell_split(command):
    return shlex.split(command) if command else []


def run_command(command, cwd, env=None):
    print("+", " ".join(shlex.quote(part) for part in command))
    subprocess.run(command, cwd=str(cwd), env=env, check=True)


def touch_stamp(path):
    if not path:
        return
    stamp = Path(path)
    stamp.parent.mkdir(parents=True, exist_ok=True)
    stamp.write_text("ok\n", encoding="ascii")


def process_templates_enabled(args):
    return args.process_templates == "true"


def mex_args(args):
    out = []
    if args.large_array_dims == "true":
        out.append("-largeArrayDims")
    else:
        out.append("-compatibleArrayDims")
    if args.debug_mex == "true":
        out.append("-g")
    if args.verbose_mex == "true":
        out.append("-v")
    return out


def object_ext():
    return "obj" if os.name == "nt" else "o"


def ensure_pyf95pp(args):
    if not args.pyf95pp_script:
        raise SystemExit(
            "Template generation is enabled, but --pyf95pp-script was not set."
        )


def generate(args):
    if not process_templates_enabled(args):
        print("Skipping template generation because process_templates=false")
        return

    ensure_pyf95pp(args)

    root = Path(args.source_root)
    env = os.environ.copy()
    if args.pyf95pp_pythonpath:
        extra_path = args.pyf95pp_pythonpath
        if env.get("PYTHONPATH"):
            extra_path = extra_path + os.pathsep + env["PYTHONPATH"]
        env["PYTHONPATH"] = extra_path

    python_cmd = shell_split(args.pyf95pp_python)
    if not python_cmd:
        raise SystemExit("Empty --pyf95pp-python command")

    run_command(
        python_cmd
        + [
            args.pyf95pp_script,
            "--sources=MatlabAPImx.F90T",
            '--std=f03',
            "-x",
        ],
        root,
        env=env,
    )

    run_command(
        python_cmd
        + [
            args.pyf95pp_script,
            "--sources=test_mx.F90T instantiate.F90T",
            "--std=f03",
            "-x",
        ],
        root / "tests",
        env=env,
    )


def build_core(args):
    root = Path(args.source_root)
    mex_cmd = shell_split(args.mex_cmd)
    if not mex_cmd:
        raise SystemExit("Empty --mex-cmd command")

    base_args = mex_args(args)
    run_command(mex_cmd + base_args + ["-c", "MatlabAPImx.F90"], root)
    run_command(mex_cmd + base_args + ["-c", "MatlabAPImex.f"], root)


def build_tests(args):
    root = Path(args.source_root)
    mex_cmd = shell_split(args.mex_cmd)
    if not mex_cmd:
        raise SystemExit("Empty --mex-cmd command")

    base_args = mex_args(args)
    objext = object_ext()
    tests_dir = root / "tests"

    for rank in TEST_RANKS:
        for typekind in TEST_TYPEKINDS:
            source = f"test_mx_{typekind}_{rank}.F90"
            command = (
                mex_cmd
                + base_args
                + [
                    "-I..",
                    source,
                    os.path.join("..", f"MatlabAPImx.{objext}"),
                    os.path.join("..", f"MatlabAPImex.{objext}"),
                ]
            )
            run_command(command, tests_dir)


def build_all(args):
    generate(args)
    build_core(args)
    build_tests(args)


def run_tests(args):
    root = Path(args.source_root)
    matlab_cmd = shell_split(args.matlab_cmd)
    if not matlab_cmd:
        raise SystemExit("Empty --matlab-cmd command")

    command = matlab_cmd + ["-batch", "run('run_tests.m')"]
    run_command(command, root)


def clean(args):
    root = Path(args.source_root)
    tests_dir = root / "tests"

    for pattern in ["*.mod", "*.o", "*.obj", "*.mex*"]:
        for path in glob.glob(str(root / pattern)):
            Path(path).unlink()
        for path in glob.glob(str(tests_dir / pattern)):
            Path(path).unlink()


def main():
    args = parse_args()
    try:
        if args.action == "generate":
            generate(args)
        elif args.action == "build-core":
            build_core(args)
        elif args.action == "build-tests":
            build_tests(args)
        elif args.action == "build-all":
            build_all(args)
        elif args.action == "test":
            run_tests(args)
        elif args.action == "clean":
            clean(args)
        else:
            raise SystemExit("Unknown action")
    except subprocess.CalledProcessError as exc:
        raise SystemExit(exc.returncode) from exc

    touch_stamp(args.stamp)


if __name__ == "__main__":
    main()
