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
