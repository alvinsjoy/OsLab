#include <dirent.h> 
#include <stdio.h> 
int main() { 
    DIR *dir = opendir("."); 
    if (dir) {
        struct dirent *entry; 
        printf("Current Directory Contents\n");
        while ((entry = readdir(dir)) != NULL) { 
            printf("%s\n", entry->d_name); 
        } 
        closedir(dir); 
    } 
    return 0; 
}