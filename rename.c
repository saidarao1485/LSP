//Develop a C program to rename a file from "oldname.txt" to "newname.txt"?
#include <stdio.h>
int main()
{
    char oldname[100], newname[100];
    printf("Enter the current filename: ");
    scanf("%s", oldname);
    printf("Enter the new filename: ");
    scanf("%s", newname);
    if (rename(oldname, newname) == 0) {
        printf("File renamed successfully from '%s' to '%s'\n", oldname, newname);
    } else {
        perror("Error renaming file");
    }
    return 0;
}

