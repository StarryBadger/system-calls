#include "main.h"

int main(int argc, char **argv)
{
    /*
    You are expected to make use of File Management
    syscalls for this part.

    **INPUT**
    Filename will be given as input from the command line.
    */

    // Write your code here

    char *filename = argv[1];
    char rev[9] = "_reverse";
    int length = strlen(filename), i, j;
    char newfile[length + 9];
    for (i = length - 1; i >= 0; i--)
        if (filename[i] == '.')
            break;
    for (int j = 0; i < i; j++)
    {
        newfile[j] = filename[j];
    }
    newfile[i] = '\0';
    strcat(newfile, "_reverse");
    strcat(newfile, filename + i);
    printf("%s", newfile);
    return 0;
}