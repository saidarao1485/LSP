//Develop a C program to move a file from one directory to another?
#include <stdio.h>
int main() {
    char source[256];
    char destination[256];
    printf("Enter source file path: ");
    scanf("%s", source);
    printf("Enter destination file path: ");
    scanf("%s", destination);
    if (rename(source, destination) == 0) {
        printf("File moved successfully.\n");
    } else {
        perror("Error moving file");
    }
    return 0;
}

