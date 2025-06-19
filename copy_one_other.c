//Write a C program to copy the contents of one file to another?
#include <stdio.h>
int main()
{
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    int ch;
    printf("Enter the source file name: ");
    scanf("%s", sourceName);
    printf("Enter the destination file name: ");
    scanf("%s", destName);
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }
    printf("Content copied successfully from '%s' to '%s'\n", sourceName, destName);
    fclose(sourceFile);
    fclose(destFile);
    return 0;
}


