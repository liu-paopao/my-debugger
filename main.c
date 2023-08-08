#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{
	if (argc < 2) {
	    printf("No executable file specified!\n");
	    return -1;
	}
	const char *name = argv[1];
	pid_t pid = fork();
	int wait_status;
	if (pid == 0) {
		// child process ==> debuggee
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execl(name, "debuggee", NULL, NULL);
	} else if (pid > 0) {
		// parent process ==> debugger
		waitpid(pid, &wait_status, 0);
		ptrace(PTRACE_KILL, pid, 0, 0);
	} else {
		printf("Fork error!");
		return -1;
	}
	return 0;
}
