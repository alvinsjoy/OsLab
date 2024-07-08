/*
Imagine you are organizing a football tournament. You are issuing two classes of tickets (Class A and Class B) for entry into the stadium.
However, the stadium has only one entrance, and everyone can enter only through this entrance.
The amount of time taken to verify the tickets varies among individuals. And you have implemented certain conditions for entry:
a) When two persons with different ticket types reach the gate, the person with a Class A ticket should enter first.
b) When two persons with Class B tickets reach the gate, the older person should enter the stadium first.
c) When two persons with Class A tickets reach the gate, the name of the person should be considered for entrance.
Write a C program to implement this situation. Print average waiting time for each class.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define A 0
#define B 1

struct class{
    int priority;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    bool executed;
    int age;
    char name[20];
} ticket[20], temp;

void main(){
    int n;
    printf("Enter the number of persons: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        printf("\nEnter the name, age, priority (0 for A, 1 for B), and time taken of person %d: ", i+1);
        scanf("%s %d %d %d", ticket[i].name, &ticket[i].age, &ticket[i].priority, &ticket[i].burstTime);
        ticket[i].executed = false;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(ticket[j].priority > ticket[j + 1].priority){
                temp = ticket[j];
                ticket[j] = ticket[j + 1];
                ticket[j + 1] = temp;
            }
            else if(ticket[j].priority == ticket[j + 1].priority){
                if(ticket[j].priority == B){
                    if(ticket[j].age < ticket[j + 1].age){
                        temp = ticket[j];
                        ticket[j] = ticket[j + 1];
                        ticket[j + 1] = temp;
                    }
                } 
                else if(ticket[j].priority == A){
                    if(strcmp(ticket[j].name, ticket[j + 1].name) > 0){
                        temp = ticket[j];
                        ticket[j] = ticket[j + 1];
                        ticket[j + 1] = temp;
                    }
                }
            }
        }
    }
    
    int time = 0, executedCount = 0;
    float waitA = 0.0, turnaroundA = 0.0;
    float waitB = 0.0, turnaroundB = 0.0;
    int countA = 0, countB = 0;

    while(executedCount < n){
        int min = -1;
        for(int i = 0; i < n; i++){
            if(!ticket[i].executed){
                min = i;
                break;
            }
        }
        
        if(min != -1){
            ticket[min].executed = true;
            time += ticket[min].burstTime;
            ticket[min].completionTime = time;
            ticket[min].turnaroundTime = ticket[min].completionTime;
            ticket[min].waitingTime = ticket[min].turnaroundTime - ticket[min].burstTime;
            
            if(ticket[min].priority == A){
                waitA += ticket[min].waitingTime;
                turnaroundA += ticket[min].turnaroundTime;
                countA++;
            }
            else{
                waitB += ticket[min].waitingTime;
                turnaroundB += ticket[min].turnaroundTime;
                countB++;
            }
            executedCount++;
        }
        else
            time++;
    }
    
    if(countA > 0){
        printf("Average waiting time for Class A = %f\n", waitA / countA);
        printf("Average Turnaround Time for Class A = %f\n", turnaroundA / countA);
    }
    else
        printf("No Class A tickets\n");
    
    if(countB > 0){
        printf("Average waiting time for Class B = %f\n", waitB / countB);
        printf("Average Turnaround Time for Class B = %f\n", turnaroundB / countB);
    }
    else
        printf("No Class B tickets\n");
}
