#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	pid_t f;
	f = fork();
	if(f == 0)
		printf("Parent Process: %d\nChild process: %d\n", getppid(), getpid());
	else if(f < 0){
		printf("Child creation failed");
		exit(0);
	}
}
