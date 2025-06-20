//Develop a C program to check if a directory named "Test" exists in the current directory?
#include <stdio.h>
#include <dirent.h>
int main()
{
    DIR *dir = opendir("Test");
    if (dir)
    {
        printf("Directory 'Test' exists\n");
        closedir(dir);
    } 
    else
    {
        printf("Directory 'Test' does NOT exist\n");
    }
    return 0;
}

