//Write a C program to get the size of a file named "file.txt"?
#include <stdio.h>
int main()
{
    FILE *file = fopen("file.txt", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    long size = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        size++;
    }
    fclose(file);
    printf("Size of 'file.txt': %ld bytes\n", size);
    return 0;
}


