#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check(int need[][3], int work[3], int i){
    if((need[i][0] <= work[0]) && (need[i][1] <= work[1]) && (need[i][2] <= work[2]))
        return true;
    else return false;
}
void main(){
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    int allocated[n][3], max[n][3], need[n][3], available[3], safeSequence[n], work[3];
    int count = 0;
    bool finished[n];
    for(int i = 0; i < n; i++){
        printf("Enter the matrix for process %d\n", i + 1);
        printf("Max matrix:\n");
        scanf("%d %d %d", &max[i][0], &max[i][1], &max[i][2]);
        printf("Allocated matrix:\n");
        scanf("%d %d %d", &allocated[i][0], &allocated[i][1], &allocated[i][2]);

        need[i][0] = max[i][0] - allocated[i][0];
        need[i][1] = max[i][1] - allocated[i][1];
        need[i][2] = max[i][2] - allocated[i][2];

        safeSequence[i] = 0;
        finished[i] = false;
    }
    printf("Enter the available matrix:\n");
    scanf("%d %d %d", &available[0], &available[1], &available[2]);
    work[0] = available[0];
    work[1] = available[1];
    work[2] = available[2];
    while(count < n){
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(!finished[i] && check(need, work, i)){
                work[0] += allocated[i][0];
                work[1] += allocated[i][1];
                work[2] += allocated[i][2];
                safeSequence[count++] = i + 1;
                finished[i] = true;
                flag = true;
            }
        }
        if(!flag){
            printf("No safe sequence found");
            exit(0);
        }
    }
    printf("Safe sequence: ");
    for(int i = 0; i < n; i++)
        printf("%d, ", safeSequence[i]);
}