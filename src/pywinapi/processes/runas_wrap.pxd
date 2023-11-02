cdef extern from "runas_wrap.h":
    int runas(char *executable, char *args, char *cwd, int timeout)
