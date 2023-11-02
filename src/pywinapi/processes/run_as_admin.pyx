cimport runas_wrap
import cython

def run_as_admin(exe: str, args: list, cwd: str = None, timeout = 0) -> int:
    """
    Run executable as admin (windows only)
    """
    print("trying to run as admin")
    workdir: cython.pointer(cython.char) = cython.cast(cython.pointer(cython.char), cython.NULL)
    if cwd:
        cwd = cwd.encode('utf-8')

    return runas_wrap.runas(
        exe.encode('utf-8'),
        (' '.join(map(str, args))).encode('utf-8'),
        workdir,
        timeout
    )
