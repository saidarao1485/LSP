//Implement a C program to create a new directory named "Test" in the current directory?
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    const char *dirname = "Test";

    if (mkdir(dirname, 0755) == 0) {
        printf("Directory '%s' created successfully.\n", dirname);
    } else {
        perror("Error creating directory");
    }

    return 0;
}

