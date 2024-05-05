#include <stdio.h>
struct process{
    char name[10];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
}p[20], temp;
void main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter process details (name, arrival time, burst time):\n");
        printf("P%d: ", i + 1);
        scanf("%s %d %d", p[i].name, &p[i].arrivalTime, &p[i].burstTime);
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(p[j].arrivalTime > p[j + 1].arrivalTime){
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    int time = 0, execution = 0;
    float wait = 0, turnaround = 0.0;
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++){
        execution = p[i].burstTime;
        time += execution;
        p[i].completionTime = time;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].name, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
        wait = wait + p[i].waitingTime;
        turnaround = turnaround + p[i].turnaroundTime;        
    }
    printf("Average Waiting Time=%f\n",wait/n);
    printf("Average turnaround Time=%f\n",turnaround/n);
}