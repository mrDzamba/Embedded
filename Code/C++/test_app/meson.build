#
# Sample C++ project using meson
#
# Developed by: MrDzamba dzamba@gmail.com
#

project(
    'test_app',
    'cpp',
    version : '0.0.1',
    default_options : ['warning_level=3', 'cpp_std=gnu++17'],
)

ccpp = meson.get_compiler('cpp')

project_arguments = [
    '-Walloc-zero',
    '-Walloca',
    '-Wbad-function-cast',
    '-Wcast-align',
    '-Wcast-qual',
    '-Wconversion',
    '-Wdouble-promotion',
    '-Wduplicated-branches',
    '-Wduplicated-cond',
    '-Wfloat-equal',
    '-Wimplicit-fallthrough=4',
    '-Wjump-misses-init',
    '-Wlogical-op',
    '-Wmissing-include-dirs',
    '-Wmissing-prototypes',
    '-Wnested-externs',
    '-Wnull-dereference',
    '-Wpacked',
    '-Wredundant-decls',
    '-Wshadow',
    '-Wstack-protector',
    '-Wstringop-truncation',
    '-Wswitch-default',
    '-Wswitch-enum',
    '-Wswitch',
    '-Wuninitialized',
    '-Wunsafe-loop-optimizations',
    '-Wunsuffixed-float-constants',
    '-Wunused-local-typedefs',
    '-Wunused-macros',
    '-Wwrite-strings',
]

add_project_arguments(ccpp.get_supported_arguments(project_arguments), language : 'cpp')

inc_dir = []

subdir('inc')
subdir('src')
subdir('test')
