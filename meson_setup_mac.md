meson setup builddir \
  -Dpyf95pp_python='pixi run python' \
  -Dpyf95pp_script=$HOME/slash/bin/PyF95++ \
  -Dpyf95pp_pythonpath=$HOME/slash/lib/python2.7/site-packages \
  -Dmex_cmd=/Applications/MATLAB_R2024b.app/bin/maca64/mex \
  -Dmatlab_cmd=/Applications/MATLAB_R2024b.app/bin/maxa64/matlab