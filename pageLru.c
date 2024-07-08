#include <stdio.h>
#include <string.h>

int n, hit = 0, miss = 0;
char page[50], frame[50];
int counter[50];

int inFrame(char item){
    for(int i = 0; i < n; i++){
        if(item == frame[i]){
            return i;
        }
    }
    return -1;
}

int findLRU(){
    int max = counter[0];
    int lruIndex = 0;

    for (int i = 1; i < n; i++){
        if (counter[i] > max){
            max = counter[i];
            lruIndex = i;
        }
    }
    return lruIndex;
}

void main(){
    printf("Enter the frame size: ");
    scanf("%d", &n);
    printf("Enter the page string: ");
    scanf("%s", page);
    for(int i = 0; i < n; i++){
        frame[i] = ' ';
        counter[i] = 0;
    }
    for(int i = 0; page[i] != '\0'; i++){
        int index = inFrame(page[i]);

        if(index != -1){
            hit++;
            counter[index] = 0;
        }
        else{
            miss++;
            int lruIndex = findLRU();
            frame[lruIndex] = page[i];
            counter[lruIndex] = 0;
        }
        for(int j = 0; j < n; j++){
            if(frame[j] != ' '){
                counter[j]++;
            }
        }
        for(int j = 0; j < n; j++){
            if(frame[j] != ' '){
                printf("%c ", frame[j]);
            }
            else{
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\nHit Count: %d", hit);
    printf("\nMiss Count: %d", miss);
    printf("\nHit Ratio: %f", (float)hit / (hit + miss));
    printf("\nMiss Ratio: %f", (float)miss / (hit + miss));
}
