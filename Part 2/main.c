#include "main.h"

int main(int argc, char **argv)
{

    /*
    When fork creates a child process B as a copy of A
    the return value of fork is set as 0 in B where as
    it is set to the process ID of B in parent process A.

    You can use this return value to differentiate between the child and parent process.

    **INPUT**
    String will be given as input from command line.
    */

    // Write your code here
    int length = strlen(argv[1]);
    char str[length + 1];
    strcpy(str, argv[1]);
    int check = fork();
    assert(check >= 0);
    if (check)
    {
        for (int i = 0; i < length; i++)
        {
            if (str[i] >= 97)
                str[i] -= 32;
        }
        printf("=== Parent Process ===\n%s\n", str);
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (str[i] < 97)
                str[i] += 32;
        }
        printf("=== Child Process ===\n%s\n", str);
    }

    return 0;
}