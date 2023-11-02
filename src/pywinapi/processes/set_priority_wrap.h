#pragma once
#include <stdbool.h>
#include <stdint.h>

/**
 * Set the priority (class) of the calling process and thread.
 * Relevent definitions in processthreadsapi.h
 * priority_class: a selection from PROCESS_PRIORITY_CLASS
 * thread_priority: a selection from THREAD_PRIORITY_CLASS
 */
bool set_priority(uint32_t priority_class, int thread_priority);
