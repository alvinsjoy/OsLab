#include <stdio.h>
#include <string.h>

int n, hit = 0, miss = 0;
char page[50], frame[50];
int frequency[50];

int inFrame(char item){
    for(int i = 0; i < n; i++){
        if(item == frame[i]){
            return i;
        }
    }
    return -1;
}
int findLFU(){
    int minFreq = frequency[0];
    int lfuIndex = 0;

    for (int i = 1; i < n; i++){
        if (frequency[i] < minFreq){
            minFreq = frequency[i];
            lfuIndex = i;
        }
    }
    return lfuIndex;
}
void main(){
    printf("Enter the frame size: ");
    scanf("%d", &n);
    printf("Enter the page string: ");
    scanf("%s", page);
    for(int i = 0; i < n; i++){
        frame[i] = ' ';
        frequency[i] = 0;
    }
    for(int i = 0; page[i] != '\0'; i++){
        int index = inFrame(page[i]);

        if(index != -1){
            hit++;
            frequency[index]++;
        }
        else{
            miss++;
            int lfuIndex = findLFU();
            frame[lfuIndex] = page[i];
            frequency[lfuIndex] = 1;
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
