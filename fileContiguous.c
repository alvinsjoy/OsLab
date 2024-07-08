#include <stdio.h>

struct file{
    int start;
    int size;
} file[20];

void main(){
    int n, blocks[20], no;
    printf("Enter the number of blocks:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        blocks[i] = 0;
    printf("Enter the number of files: ");
    scanf("%d", &no);
    for(int i = 0; i < no; i++){
        printf("Enter starting block for file %d: ", i + 1);
        scanf("%d", &file[i].start);
        printf("Enter size of file %d: ", i + 1);
        scanf("%d", &file[i].size);
        int canAllocate = 1;
        if(file[i].size > n || (file[i].size + file[i].start) > n)
            printf("File cannot be allocated due to lack of memory");
        else{
            for(int j = file[i].start; j < file[i].start + file[i].size; j++){
                if(blocks[j] == 1){
                    canAllocate = 0;
                    break;
                }
            }
            if(canAllocate == 1){
                printf("File Allocated to Blocks: ");
                for(int j = file[i].start; j < file[i].start + file[i].size; j++){
                    blocks[j] = 1;
                    printf("%d, ", j);
                }
                printf("\n");
            }
            else
                printf("File cannot be allocated. Blocks from %d to %d are already occupied.\n", file[i].start, file[i].start + file[i].size - 1);
        }
    }
}