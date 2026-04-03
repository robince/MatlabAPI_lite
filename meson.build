project('MatlabAPI_lite', version : '0.1.0')

py = import('python').find_installation('python3', required : true)
helper = files('tools/build.py')

process_templates = get_option('process_templates') ? 'true' : 'false'
large_array_dims = get_option('large_array_dims') ? 'true' : 'false'
debug_mex = get_option('debug_mex') ? 'true' : 'false'
verbose_mex = get_option('verbose_mex') ? 'true' : 'false'

helper_args = [
  '--source-root', meson.project_source_root(),
  '--process-templates', process_templates,
  '--pyf95pp-python', get_option('pyf95pp_python'),
  '--pyf95pp-script', get_option('pyf95pp_script'),
  '--pyf95pp-pythonpath', get_option('pyf95pp_pythonpath'),
  '--mex-cmd', get_option('mex_cmd'),
  '--matlab-cmd', get_option('matlab_cmd'),
  '--large-array-dims', large_array_dims,
  '--debug-mex', debug_mex,
  '--verbose-mex', verbose_mex,
]

build_inputs = files(
  'MatlabAPImx.F90T',
  'MatlabAPImex.f',
  'run_tests.m',
  'tests/test_mx.F90T',
  'tests/instantiate.F90T',
)

build_all = custom_target(
  'build-all',
  input : build_inputs,
  output : 'build-all.stamp',
  command : [py, helper, 'build-all'] + helper_args + ['--stamp', '@OUTPUT@'],
  build_by_default : true,
)

run_target(
  'generate',
  command : [py, helper, 'generate'] + helper_args,
)

run_target(
  'build-core',
  command : [py, helper, 'build-core'] + helper_args,
)

run_target(
  'build-tests',
  command : [py, helper, 'build-tests'] + helper_args,
)

run_target(
  'clean-artifacts',
  command : [py, helper, 'clean'] + helper_args,
)

test(
  'matlab-tests',
  py,
  args : [helper, 'test'] + helper_args,
  depends : build_all,
  suite : 'matlab',
)

summary(
  {
    'process templates' : get_option('process_templates'),
    'PyF95++ python command' : get_option('pyf95pp_python'),
    'PyF95++ script' : get_option('pyf95pp_script'),
    'PyF95++ PYTHONPATH' : get_option('pyf95pp_pythonpath'),
    'mex command' : get_option('mex_cmd'),
    'matlab command' : get_option('matlab_cmd'),
  },
  section : 'MatlabAPI_lite',
)
