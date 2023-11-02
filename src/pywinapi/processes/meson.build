# where to place extension modules & python files so they can be imported by python
import_path = 'pywinapi' / 'processes'

modules_map = {
    'run_as_admin': files([
        'run_as_admin.pyx',
        'runas_wrap.c',
    ]),
    'set_priority': files([
        'set_priority.pyx',
        'set_priority_wrap.c',
    ]),
    'winapi_defs': files([
        'winapi_defs.pyx',
    ]),
}
# only one namespace per extension module is possible.
foreach ext_name, source_files: modules_map
    py.extension_module(
        ext_name,
        source_files,
        dependencies: [py_dep],
        subdir: import_path,
        override_options: ['cython_language=c'],
        cython_args: ['-I' + meson.current_source_dir()],
        include_directories: project_includes,
        link_args: ['-lshell32'],
        install: true,
    )
endforeach


py.install_sources(
    '__init__.py',
    pure: false,
    subdir: import_path
)
