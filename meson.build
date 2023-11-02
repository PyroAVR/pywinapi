project(
    'pywinapi',
    ['c', 'cython'],
    version: '0.0.1'
)

# locate python, see python_path option for details
py_path = get_option('python_path')
if py_path == ''
    py = import('python').find_installation(modules: ['cython'])
elif py_path.startswith('/')
    py = import('python').find_installation(py_path, modules: ['cython'])
else
    py = import('python').find_installation(
        meson.current_source_dir() / py_path,
        modules: ['cython'],
    )
endif

py_dep = py.dependency()

project_includes = include_directories('include')

if get_option('debug_logging')
    add_project_arguments(['-DPYWINAPI_DEBUG'])
endif

if not py_dep.found()
    error('Could not find python, which is required for cythonize')
endif

subdir('src' / 'pywinapi' / 'processes')
#subdir('src' / 'drvinst')

# python package validity marker and import logic
py.install_sources(
    'src' / 'pywinapi' / '__init__.py',
    pure: false,
    subdir: 'pywinapi'
)
