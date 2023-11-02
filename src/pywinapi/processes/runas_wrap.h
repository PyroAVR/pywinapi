#pragma once

/**
 * Run an arbitrary executable, syncrhonously, as administrator.
 * Wraps ShellExecuteExU and SHELLEXECUTEINFOA.
 * executable: Windows path (ASCII encoded) to the program to run
 * args: argument string to pass to the executable, ASCII encoded
 * cwd: working directory to start executable in, ASCII encoded
 * timeout: timeout in ms for WaitForSingleObject. When 0, return immediately
 * returns: WinAPI error code.
 */
unsigned long runas(char *executable, char *args, char *cwd, int timeout);
