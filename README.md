# PyWinAPI

## w i n  b   l    o     w      s

This is a collection of wrappers around some WinAPI functions, and Python
bindings to them.

## Installation from source

`pip install .`

That's it. `meson-python` takes care of the rest.
For the curious, the pure Python part of the packaging which requires
installation of `__init__.py` into each subdirectory to be searched as a
module, is done by meson, via `py.install_sources`

Installation of MSVC 2019 or MinGW is not covered here. This library has only
been tested with MSVC, although MinGW should work without trouble. Adding
`__stdcall` to the C function definitions `*.pxd` files may be necessary, since
Python is built with MSVC 2019 for Windows, and the calling conventions need to
match. **MinGW is untested.**

## Caveats

Windows types, like `DWORD`, are replaced with their standard C types. It makes the Python interface a lot nicer.

## Contributing

Forks, PRs, and bug reports are all welcome! Please use Github Issues to file bug reports.
