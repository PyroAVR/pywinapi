#include "runas_wrap.h"

#include "msapi_utf8.h"

#include <windows.h>
#include <shellapi.h>

#include <string.h>
#include <stdio.h>

unsigned long runas(char *executable, char *args, char *cwd, int timeout) {
    SHELLEXECUTEINFOA shExecInfo;
    DWORD err;

    if((cwd != NULL) && (strlen(cwd) == 0)) {
        cwd = NULL;
    }

    if(timeout < 0) {
        timeout = INFINITE;
    }

    printf("runas executable=%s args=%s cwd=%s timeout=%i", executable, args, cwd, timeout);
    
    shExecInfo.cbSize = sizeof(SHELLEXECUTEINFOA);
    shExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_NOASYNC;
    shExecInfo.hwnd = NULL;
    shExecInfo.lpVerb = "runas";
    shExecInfo.lpFile = executable;
    shExecInfo.lpParameters = args;
    shExecInfo.lpDirectory = cwd;
    shExecInfo.lpClass = NULL;
    shExecInfo.nShow = SW_SHOW;
    shExecInfo.hInstApp = NULL;

    err = ERROR_SUCCESS;
    if(!ShellExecuteExU(&shExecInfo)) {
        err = GetLastError();
    }
    
    switch(err) {
        case ERROR_SUCCESS:
            switch(WaitForSingleObject(shExecInfo.hProcess, timeout)) {
                case WAIT_TIMEOUT:
                    TerminateProcess(shExecInfo.hProcess, 0);
                break;

                case WAIT_ABANDONED:
                    printf("abandoned\n");
 
                case WAIT_OBJECT_0:
                    printf("signaled (exited)\n");
                break;

                case WAIT_FAILED:
                    printf("failed\n");
                break;
            }
        break;

#if defined(PYWINAPI_DEBUG)
		case ERROR_CANCELLED:
			fprintf(stderr, "Operation cancelled by the user or due to missing data\n");
        break;

		case ERROR_FILE_NOT_FOUND:
			fprintf(stderr, "Could not find specified executable: %s\n", executable);
        break;

		default:
			fprintf(stderr, "ShellExecuteEx failed: %i", err);
        break;
#endif
    }

    return err;
}
