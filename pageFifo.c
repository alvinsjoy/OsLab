#include <stdio.h>
int front = -1, rear = -1, n, hit = 0, miss = 0;
char page[50], frame[50];
void enqueue(char item){
    if(front == -1){
        front++;
    }
    else if((rear + 1) % n == front)
        front = (front + 1) % n;
    rear = (rear + 1) % n;
    frame[rear] = item;
}
int inFrame(char item){
    for(int i = 0; i < n; i++){
        if(item == frame[i]){
            return 1;
        }
    }
    return 0;
}
void main(){
    printf("Enter the frame size: ");
    scanf("%d", &n);
    printf("Enter the page string: ");
    scanf("%s", page);
    for(int i = 0; i < n; i++)
        frame[i] = ' ';
    for(int i = 0; page[i] != '\0'; i++){
        if(inFrame(page[i]) == 0){
            enqueue(page[i]);
            miss++;
        }
        else
            hit++;
        for(int j = 0; j < n; j++)
            printf("%c ", frame[j]);
        printf("\n");
    }
    printf("\nHit Count: %d", hit);
    printf("\nMiss Count: %d", miss);
    printf("\nHit Ratio: %f", (float)hit / (float)(hit + miss));
    printf("\nMiss Ratio: %f", (float)miss / (float)(hit + miss));
}