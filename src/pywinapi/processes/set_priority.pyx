cimport set_priority_wrap

def set_priority(priority_class: ProcessPriorityClass, thread_priority: ThreadPriorityClass) -> bool:
    return set_priority_wrap.set_priority(priority_class, thread_priority)
