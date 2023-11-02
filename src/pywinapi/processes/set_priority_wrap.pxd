cdef extern from "set_priority_wrap.h":
    bint set_priority(int priority_class, int thread_priority);
