#include <stdio.h>
#include <stdlib.h>
int fcfs(int requests[], int numRequests){
    int totalSeekTime = 0, currentTrack = 0;
    for(int i = 0; i < numRequests; i++){
        totalSeekTime += abs(currentTrack - requests[i]);
        currentTrack = requests[i];
    }
    return totalSeekTime;
}
int scan(int requests[], int numRequests){
    int totalSeekTime = 0, currentTrack = 0;
    int direction = 1;
    for(int i = 0; i < numRequests; i++){
        while(currentTrack >= 0 && currentTrack < 200){
            if(currentTrack == requests[i]){
                requests[i] = -1;
                break;
            }
            totalSeekTime++;
            currentTrack += direction;
        }
        if(currentTrack == 200){
            direction = -1;
            currentTrack = 199;
        }
        else if(currentTrack == -1){
            direction = 1;
            currentTrack = 0;
        }
    }
    return totalSeekTime;
}
int cscan(int requests[], int numRequests){
    int totalSeekTime = 0, currentTrack = 0;
    for(int i = 0; i < numRequests; i++){
        while(currentTrack >= 0 && currentTrack < 200){
            if(currentTrack = requests[i]){
                requests[i] = -1;
                break;
            }
            totalSeekTime++;
            currentTrack++;
        }
        if(currentTrack >= 200)
            currentTrack = 0;
    }
    return totalSeekTime;
}
void main(){
    int requests[100];
    int numRequests, totalSeek;
    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);
    printf("Enter the disk requests (track numbers):\n");
    for (int i = 0; i < numRequests; i++) {
        printf("Track number %d: ", i + 1);
        scanf("%d", &requests[i]);
    }
    printf("FCFS\n");
    totalSeek = fcfs(requests, numRequests);
    printf("Total Seek Time: %d\n", totalSeek);
    printf("SCAN\n");
    totalSeek = scan(requests, numRequests);
    printf("Total Seek Time: %d\n", totalSeek);
    printf("C-SCAN\n");
    totalSeek = scan(requests, numRequests);
    printf("Total Seek Time: %d\n", totalSeek);
}