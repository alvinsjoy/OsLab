#include<stdio.h>
struct process{
    int size;
    int allocation;
};
void firstFit(struct process p[], int memory[], int n, int m ){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (memory[j] >= p[i].size) {
                p[i].allocation = j;
                memory[j] -= p[i].size;
                break;
            }
        }
    }
    printf("P\tSize\tMem\n");
    for(int i = 0; i < n; i++){
        if(p[i].allocation != -1)
            printf("%d\t%d\t%d\n", i + 1, p[i].size, p[i].allocation + 1);
        else
            printf("%d\t%d\tNoAlloc\n", i + 1, p[i].size);
    }
    for(int i = 0; i < m; i++){
        printf("Free Blocks -->");
        printf("%d/n",memory[i]);
    }
}
void worstFit(struct process p[], int memory[], int n, int m ){
    for (int i = 0; i < n; i++) {
        int maxIndex = -1;
        for (int j = 0; j < m; j++) {
            if(p[i].size <= memory[j]){
                if(maxIndex == -1 || memory[maxIndex] < memory[j])
                    maxIndex = j;
            }
        }
        if(maxIndex != -1){
            p[i].allocation = maxIndex;
            memory[maxIndex] -= p[i].size;
        }
    }
    printf("P\tSize\tMem\n");
    for(int i = 0; i < n; i++){
        if(p[i].allocation != -1)
            printf("%d\t%d\t%d\n", i + 1, p[i].size, p[i].allocation + 1);
        else
            printf("%d\t%d\tNoAlloc\n", i + 1, p[i].size);
    }
    for(int i = 0; i < m; i++){
        printf("Free Blocks -->");
        printf("%d/n",memory[i]);
    }
}
void bestFit(struct process p[], int memory[], int n, int m ){
    for (int i = 0; i < n; i++) {
        int bestIndex = -1;
        for (int j = 0; j < m; j++) {
            if(memory[j] >= p[i].size){
                if(bestIndex == -1 || memory[bestIndex] >= memory[j])
                    bestIndex = j;
            }
        }
        if(bestIndex != -1){
            p[i].allocation = bestIndex;
            memory[bestIndex] -= p[i].size;
        }
    }
    printf("P\tSize\tMem\n");
    for(int i = 0; i < n; i++){
        if(p[i].allocation != -1)
            printf("%d\t%d\t%d\n", i + 1, p[i].size, p[i].allocation + 1);
        else
            printf("%d\t%d\tNoAlloc\n", i + 1, p[i].size);
    }
    for(int i = 0; i < m; i++){
        printf("Free Blocks -->");
        printf("%d\n",memory[i]);
    }
}
void main(){
    int i, memory[100], n, m;
    struct process p[20];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the process size\n");
    for(i = 0; i < n; i++){
        printf("Process %d: ", i + 1);
        scanf("%d",&p[i].size);
        p[i].allocation = -1;
    }
    printf("Enter the number of memory blocks: ");
    scanf("%d",&m);
    printf("Enter the memory blocks\n");
    for(i = 0; i < m; i++){
        printf("Memory %d: ", i + 1);
        scanf("%d",&memory[i]);
    }
    printf("First Fit\n");
    firstFit(p, memory, n, m);
    printf("Worst Fit\n");
    worstFit(p, memory, n, m);
    printf("Best Fit\n");
    bestFit(p, memory, n, m);
}