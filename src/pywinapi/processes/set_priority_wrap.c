#include "set_priority_wrap.h"

#include <windows.h>
#include <processthreadsapi.h>

#include <stdint.h>
#include <stdbool.h>

bool set_priority(uint32_t priority_class, int thread_priority) {
    // first, set priority class of the currently running process
    bool success = SetPriorityClass(GetCurrentProcess(), priority_class);
    if(success) {
        success = SetThreadPriority(GetCurrentThread(), thread_priority);
    }
    return success;
}
