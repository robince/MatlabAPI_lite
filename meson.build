project('MatlabAPI_lite', version : '0.1.0')

py = import('python').find_installation('python3', required : true)
helper = files('tools/build.py')

process_templates = get_option('process_templates')
process_templates_flag = process_templates ? 'true' : 'false'
large_array_dims = get_option('large_array_dims') ? 'true' : 'false'
debug_mex = get_option('debug_mex') ? 'true' : 'false'
verbose_mex = get_option('verbose_mex') ? 'true' : 'false'

helper_args = [
  '--source-root', meson.project_source_root(),
  '--process-templates', process_templates_flag,
  '--pyf95pp-python', get_option('pyf95pp_python'),
  '--pyf95pp-script', get_option('pyf95pp_script'),
  '--pyf95pp-pythonpath', get_option('pyf95pp_pythonpath'),
  '--mex-cmd', get_option('mex_cmd'),
  '--matlab-cmd', get_option('matlab_cmd'),
  '--large-array-dims', large_array_dims,
  '--debug-mex', debug_mex,
  '--verbose-mex', verbose_mex,
]

test_typekinds = [
  'real_c_double',
  'integer_c_int8_t',
  'integer_c_int16_t',
  'integer_c_int32_t',
  'integer_c_int64_t',
]
test_ranks = ['0', '1', '2', '3', '4', '5', '6']

template_targets = []
main_template_targets = []
test_template_targets = []

if process_templates
  generate_main = custom_target(
    'generate-main-template',
    input : files('MatlabAPImx.F90T'),
    output : 'generate-main-template.stamp',
    command : [py, helper, 'generate-main'] + helper_args + ['--stamp', '@OUTPUT@'],
  )
  generate_tests = custom_target(
    'generate-test-templates',
    input : files('tests/test_mx.F90T', 'tests/instantiate.F90T'),
    output : 'generate-test-templates.stamp',
    command : [py, helper, 'generate-tests'] + helper_args + ['--stamp', '@OUTPUT@'],
  )
  main_template_targets += [generate_main]
  test_template_targets += [generate_tests]
  template_targets += main_template_targets + test_template_targets
endif

matlabapimx_target = custom_target(
  'build-matlabapimx-object',
  input : files('MatlabAPImx.F90', 'mxInterface.inc', 'repidx.h'),
  output : 'MatlabAPImx.object.stamp',
  command : [py, helper, 'build-matlabapimx'] + helper_args + ['--stamp', '@OUTPUT@'],
  depends : main_template_targets,
  console : true,
  build_by_default : true,
)

matlabapimex_target = custom_target(
  'build-matlabapimex-object',
  input : files('MatlabAPImex.f', 'repidx.h'),
  output : 'MatlabAPImex.object.stamp',
  command : [py, helper, 'build-matlabapimex'] + helper_args + ['--stamp', '@OUTPUT@'],
  console : true,
  build_by_default : true,
)

core_targets = [matlabapimx_target, matlabapimex_target]
test_targets = []

foreach typekind : test_typekinds
  foreach rank : test_ranks
    test_name = 'test_mx_@0@_@1@'.format(typekind, rank)
    test_source = 'tests/' + test_name + '.F90'
    test_targets += custom_target(
      'build-' + test_name,
      input : files(test_source, 'repidx.h'),
      output : test_name + '.mex.stamp',
      command : [
        py,
        helper,
        'build-test',
      ] + helper_args + [
        '--test-source',
        test_name + '.F90',
        '--stamp',
        '@OUTPUT@',
      ],
      depends : core_targets + test_template_targets,
      console : true,
      build_by_default : true,
    )
  endforeach
endforeach

all_build_targets = core_targets + test_targets

if process_templates
  alias_target('generate', template_targets)
else
  run_target(
    'generate',
    command : [py, helper, 'generate'] + helper_args,
  )
endif

alias_target('build-core', core_targets)
alias_target('build-tests', test_targets)
alias_target('build-all', all_build_targets)

run_target(
  'clean-artifacts',
  command : [py, helper, 'clean'] + helper_args,
)

test(
  'matlab-tests',
  py,
  args : [helper, 'test'] + helper_args,
  depends : all_build_targets,
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
