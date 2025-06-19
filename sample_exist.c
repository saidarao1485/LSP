//Write a C program to check if a file named "sample.txt" exists in the current directory?
#include <stdio.h>
int main() {
    FILE *file;
    file = fopen("file.txt", "r");
    if (file) {
        printf("The file 'file.txt' exists in the current directory\n");
        fclose(file);
    } else {
        printf("The file 'file.txt' does NOT exist in the current directory\n");
    }
    return 0;
}

