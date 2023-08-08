#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
	printf("Init process pid is %d\n", getpid());
	pid_t pid = fork();
	if (pid == 0) {
		// child process
		printf("I am child, my pid is %d\n", getpid());
	} else if (pid > 0) {
		// parent process
		printf("I am parent, my pid is %d, my child pid is %d\n", getpid(), pid);
	} else {
		printf("Fork error!");
		return -1;
	}
	return 0;
}
