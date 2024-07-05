#include <stdio.h>
#include <string.h>

int top = -1, n, hit = 0, miss = 0;
char page[50], frame[50];

void push(char item, int *top, char stack[]){
    stack[++(*top)] = item;
}

char pop(int *top, char stack[]){
    return stack[(*top)--];
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
        if(inFrame(page[i]) == 1)
            hit++;
        else{
            miss++;
            if(top == n - 1){
                for(int j = 0; j < n - 1; j++){
                    frame[j] = frame[j + 1];
                }
                frame[n - 1] = page[i];
            }
            else
                push(page[i], &top, frame);
        }
        for(int j = 0; j < n; j++){
            if(frame[j] != ' '){
                printf("%c ", frame[j]);
            }
        }
        printf("\n");
    }
    printf("\nHit Count: %d", hit);
    printf("\nMiss Count: %d", miss);
    printf("\nHit Ratio: %f", (float)hit / (float)(hit + miss));
    printf("\nMiss Ratio: %f", (float)miss / (float)(hit + miss));
}
