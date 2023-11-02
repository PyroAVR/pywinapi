"""
windows.h must be included in order to include other headers.

From Wikipedia, regarding windows.h:

    There are a number of child header files that are automatically
    included with windows.h. Many of these files cannot simply be included
    by themselves (they are not self-contained), because of dependencies.

If your code is bad enough to have a design fault warranting a
Wikipedia page... yikes
"""
cdef extern from "windows.h":
    pass

cdef extern from "processthreadsapi.h":
    cdef enum process_priority_class:
        ABOVE_NORMAL_PRIORITY_CLASS = 0x8000
        BELOW_NORMAL_PRIORITY_CLASS = 0x4000
        HIGH_PRIORITY_CLASS = 0x80
        IDLE_PRIORITY_CLASS = 0x40
        NORMAL_PRIORITY_CLASS = 0x20
        PROCESS_MODE_BACKGROUND_BEGIN = 0x100000
        PROCESS_MODE_BACKGROUND_END = 0x200000
        REALTIME_PRIORITY_CLASS = 0x100

    cdef enum thread_priority_class:
        THREAD_MODE_BACKGROUND_BEGIN = 0x10000 
        THREAD_MODE_BACKGROUND_END = 0x20000 
        THREAD_PRIORITY_ABOVE_NORMAL = 1
        THREAD_PRIORITY_BELOW_NORMAL = -1
        THREAD_PRIORITY_HIGHEST = 2
        THREAD_PRIORITY_IDLE = -15
        THREAD_PRIORITY_LOWEST = -2
        THREAD_PRIORITY_NORMAL = 0
        THREAD_PRIORITY_TIME_CRITICAL = 15


# not available for processes without REALTIME_PRIORITY_CLASS, also not defined
# in the enums, but it is documented on MSDN under "Scheduling Priorities"
cdef enum thread_priority_realtime:
    THREAD_PRIORITY_REALTIME_N7 = -7
    THREAD_PRIORITY_REALTIME_N6 = -6
    THREAD_PRIORITY_REALTIME_N5 = -5
    THREAD_PRIORITY_REALTIME_N4 = -4
    THREAD_PRIORITY_REALTIME_N3 = -3
    THREAD_PRIORITY_REALTIME_3 = 3
    THREAD_PRIORITY_REALTIME_4 = 4
    THREAD_PRIORITY_REALTIME_5 = 5
    THREAD_PRIORITY_REALTIME_6 = 6
