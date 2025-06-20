//Implement a C program to create a new directory named "Backup" in the parent directory?
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
int main()
{
    const char *dirPath = "../Backup";
    if (mkdir(dirPath, 0755) == 0)
    {
        printf("Directory 'Backup' created successfully in the parent directory\n");
    }
    else
    {
        perror("Error creating directory");
        return 1;
    }
    return 0;
}

