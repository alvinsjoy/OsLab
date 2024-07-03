#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define THREADS 5

int buffer[BUFFER_SIZE];
int in, out = 0;
sem_t full, empty, mutex;

void *producer(void *arg){
    for(int i = 0; i < 10; i++){
        int item = rand() % 100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Produced: %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *arg){
    for(int i = 0; i < 10; i++){
        sem_wait(&full);
        sem_wait(&mutex);
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
    }
}
void main(){
    pthread_t producerThread[THREADS], consumerThread[THREADS];
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    for(int i = 0; i < THREADS; i++){
        pthread_create(&producerThread[i], NULL, producer, NULL);
        pthread_create(&consumerThread[i], NULL, consumer, NULL);
    }
    for(int i = 0; i < THREADS; i++){
        pthread_join(producerThread[i], NULL);
        pthread_join(consumerThread[i], NULL);
    }
}
