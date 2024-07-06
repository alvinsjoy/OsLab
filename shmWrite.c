#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

#define SHM_SIZE 1024
void main(){
    key_t key;
    int shmid;
    char *shm;
    key = ftok("shmfile", 'R');
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    shm = shmat(shmid, NULL, 0);
    printf("Enter the message: ");
    scanf("%[^\n]", shm);
    printf("%s\n", shm);
    shmdt(shm);
}
/*
ftok: Generates a unique key based on the file "shmfile" and an identifier 'R'.
shmget: Creates a shared memory segment with the specified key and size, and sets permissions to allow read/write.
shmat: Attaches the shared memory segment to the process's address space.
sprintf(shm, "Hello World"): Writes the string "Hello World" to the shared memory segment.
printf("%s\n", shm): Prints the content of the shared memory segment.
shmdt(shm): Detaches the shared memory segment from the process's address space.
shmctl: Destroy the shared memory segment.
*/