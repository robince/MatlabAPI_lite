MatlabAPI_lite
==============

Templated version of MatlabAPI with fewer features, but support for Matlab real types, signed integer types, and limited unsigned input compatibility

This is based on the [Fortran 95 Matlab API](http://www.mathworks.com/matlabcentral/fileexchange/25934-fortran-95-interface-to-matlab-api-with-extras) by James Tursa.

It is a stripped down version with only basic support for working with Matlab arrays. There is no sparse or complex support or many of the useful additional functions in the full MatlabAPI package. 

This is templated with [PyF95++](http://sourceforge.net/apps/mediawiki/blockit/index.php?title=PyF95%2B%2B) from the [BlockIt](http://sourceforge.net/projects/blockit/) package so it supports multiple Matlab numeric classes from one source template. Unsigned Matlab arrays are accepted on input for zero-copy access, but only when values stay within the corresponding signed range; returning unsigned Matlab classes is not supported. Empty arrays can be observed and wrapped with their dimensions preserved, but `fpAllocate` does not create empty arrays.

Also it replaces the common block approach with `c_f_pointer` from `iso_c_binding`. So if you have a compiler that supports it and want to use data types other than double maybe it is useful. Otherwise check out the main MatlabAPI package. 

Build with Meson
----------------

`make.m` remains as the original MATLAB-side build script, but the repository now also includes a Meson wrapper that can drive template generation, `mex` compilation, and MATLAB batch tests from the shell.

Install the host-side tools with Homebrew:

```sh
brew install meson ninja
```

Configure a build directory:

```sh
meson setup builddir \
  -Dmex_cmd=/path/to/matlab/bin/mex \
  -Dmatlab_cmd=/path/to/matlab/bin/matlab
```

If you want to build from the checked-in generated sources without running PyF95++, disable template processing:

```sh
meson setup builddir \
  -Dprocess_templates=false \
  -Dmex_cmd=/path/to/matlab/bin/mex \
  -Dmatlab_cmd=/path/to/matlab/bin/matlab
```

If you want Meson to regenerate templates via the legacy PyF95++ toolchain, point it at the Python command, the PyF95++ script, and the `blockit` `PYTHONPATH` entry. For example, with a Pixi-managed Python 2.7 environment and an existing install in `~/slash`:

```sh
meson setup builddir \
  -Dpyf95pp_python='pixi run python' \
  -Dpyf95pp_script=$HOME/slash/bin/PyF95++ \
  -Dpyf95pp_pythonpath=$HOME/slash/lib/python2.7/site-packages \
  -Dmex_cmd=/path/to/matlab/bin/mex \
  -Dmatlab_cmd=/path/to/matlab/bin/matlab
```

Build and test with:

```sh
meson compile -C builddir
meson test -C builddir
```

The Meson graph tracks template generation and mex compilation incrementally. If you change one generated test source, only that mex target rebuilds; if you change a template, Meson reruns the relevant template-generation step and the binaries that depend on it. The individual `mex` invocations are serialized because parallel `mex` processes were not reliable in this environment.

If your MATLAB `mex` configuration changes outside Meson, such as switching compiler toolchains or changing `mex -setup`, Meson will not detect that automatically because the source files are unchanged. In that case, force a full binary rebuild while keeping the generated `.F90` files with:

```sh
meson compile -C builddir clean-artifacts
meson compile -C builddir
```

`clean-artifacts` removes compiled outputs such as `.o`, `.obj`, `.mod`, and `.mex*`, but leaves template outputs alone. Use that when you want to rebuild all binaries without reprocessing templates.

Additional convenience targets are available through Meson:

```sh
meson compile -C builddir generate
meson compile -C builddir build-core
meson compile -C builddir build-tests
meson compile -C builddir clean-artifacts
```

The Meson wrapper does not replace MATLAB compiler configuration. `mex` must already be configured for your Fortran compiler via MATLAB's normal `mex -setup Fortran` flow.
