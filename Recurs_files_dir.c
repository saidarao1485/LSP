//Write a C program to recursively list all files and directories in a given directory?
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
void listFiles(const char *path)
{
    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        char fullPath[512];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        printf("%s\n", fullPath);

        struct stat info;
        if (stat(fullPath, &info) == 0 && S_ISDIR(info.st_mode)) {
            listFiles(fullPath);
        }
    }
    closedir(dir);
}
int main()
{
    char path[256];
    printf("Enter directory path: ");
    scanf("%s", path);
    listFiles(path);
    return 0;
}

