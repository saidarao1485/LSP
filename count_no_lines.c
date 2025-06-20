//Implement a C program to count the number of lines in a file named "file.txt"?
#include <stdio.h>
int main()
{
    FILE *file = fopen("file.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    int ch;
    int lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
	{
            lines++;
        }
    }
    fclose(file);
    printf("Number of lines in file.txt: %d\n", lines);
    return 0;
}

