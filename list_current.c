//Implement a C program to list all files in the current directory?
/*#include <stdlib.h>
int main() {
    system("ls");
    return 0;
}*/
#include <stdio.h>
#include <dirent.h>
int main()
{
    struct dirent *entry;
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Unable to open current directory");
        return 1;
    }
    printf("Files in current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir);
    return 0;
}


