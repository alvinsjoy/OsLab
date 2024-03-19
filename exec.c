#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(){
	pid_t pid = fork();

	if (pid < 0){
		perror("fork failed");
    	exit(EXIT_FAILURE);

	}
	else if(pid == 0){

		// Child process
		printf("Child process (PID %d): Executing ls -l\n", getpid());

		// Open text.txt
		char *args[] = {"gedit", "text.txt", NULL};
		execvp(args[0], args);

		// If execvp fails, print an error
		perror("execvp failed");
		exit(EXIT_FAILURE);

	}
	else{
		// Parent process
		printf("Parent process (PID %d): Waiting for child.\n", getpid());
		wait(NULL); // Wait for the child process to finish
		printf("Child process completed.\n");
	}
}
