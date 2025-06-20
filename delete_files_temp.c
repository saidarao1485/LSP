//Develop a C program to delete all files in a directory named "Temp"?
/*#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
int main()
{
    DIR *dir = opendir("Temp");
    struct dirent *entry;
    char path[512];
    if (dir == NULL)
    {
        perror("Cannot open Temp directory");
        return 1;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        snprintf(path, sizeof(path), "Temp/%s", entry->d_name);
        if (remove(path) == 0)
	{
            printf("Deleted: %s\n", path);
        }
       	else
       	{
            perror("Failed to delete");
        }
    }
    closedir(dir);
    return 0;
}*/
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    char path[512];

    // Check if directory exists
    dir = opendir("Temp");
    if (dir == NULL)
    {
        // Try to create it
        if (mkdir("Temp", 0777) == -1)
        {
            perror("Failed to create Temp directory");
            return 1;
        }
        else
        {
            printf("Temp directory was missing, so it has been created.\n");
            return 0; // Nothing to delete, so exit
        }
    }

    // Proceed to delete contents
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "Temp/%s", entry->d_name);
        if (remove(path) == 0)
        {
            printf("Deleted: %s\n", path);
        }
        else
        {
            perror("Failed to delete");
        }
    }

    closedir(dir);
    return 0;
}


