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

    char filename[1000], newfilename[1000 + 8];
    char rev[9] = "_reverse";
    scanf("%s", filename);

    int length = strlen(filename), i, j;
    for (i = length - 1; i >= 0; i--)
        if (filename[i] == '.')
            break;
    if (i == -1)
        i = length;
    int c = 0;
    for (j = 0; j < i; j++)
    {
        newfilename[c++] = filename[j];
    }

    printf("%s", newfilename);
    return 0;
}