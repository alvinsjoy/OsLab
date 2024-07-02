#include <stdio.h>

int counter = 0;
int semaphore = 1;

void wait(int semaphore){
    while(semaphore <= 0);
    semaphore -= 1;
}
void signal(int semaphore){
    semaphore += 1;
}
void main(){
    for(int i = 0; i < 10; i++){
        wait(semaphore);
        counter++;
        printf("Counter: %d\n", counter);
        signal(semaphore);
    }
}