//Implement a C program to delete a file named "delete_me.txt"?
#include <stdio.h>
int main() {
    const char *filename = "delete_me.txt";
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully\n", filename);
    } else {
        perror("Error deleting file");
    }
    return 0;
}

