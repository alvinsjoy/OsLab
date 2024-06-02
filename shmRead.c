#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

#define SHM_SIZE 1024
void main(){
    int shmid;
    key_t key;
    char *shm;
    key = ftok("shmfile", 'R');
    shmid = shmget(key, SHM_SIZE, 0666);
    shm = shmat(shmid, NULL, 0);
    printf("Message from shared memory: %s\n", shm);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
}