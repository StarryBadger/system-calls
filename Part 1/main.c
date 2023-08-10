#include "main.h"
void reverseString(char *str, int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
int main(int argc, char **argv)
{
    /*
    You are expected to make use of File Management
    syscalls for this part.

    **INPUT**
    Filename will be given as input from the command line.
    */

    // Write your code here

    mkdir("Copies", 0755);
    char *filename = argv[1];
    int length = strlen(filename);
    int i;
    char newfile[length + 16];
    strcpy(newfile, "Copies/");
    for (i = length - 1; i >= 0; i--)
        if (filename[i] == '.')
            break;
    if (i == -1)
    {
        strcat(newfile, filename);
        strcat(newfile, "_reverse");
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            newfile[j + 7] = filename[j];
        }
        newfile[i + 7] = '\0';
        strcat(newfile, "_reverse");
        strcat(newfile, filename + i);
    }
    int inputFile = open(filename, O_RDONLY);
    assert(inputFile != -1);
    int outputFile = open(newfile, O_WRONLY | O_CREAT);
    assert(outputFile != -1);
    struct stat st;
    stat(filename, &st);
    chmod(newfile, st.st_mode);
    char buffer[BUFFER_SIZE + 1];
    int flag = 1;
    off_t fileSize = lseek(inputFile, 0, SEEK_END);
    ssize_t bytesRead;
    while (flag)
    {
        assert(fileSize != -1);
        if (fileSize <= BUFFER_SIZE)
        {
            flag = 0;
            assert(lseek(inputFile, -1 * fileSize, SEEK_CUR) != -1);
            bytesRead = read(inputFile, buffer, fileSize);
        }
        else
        {
            assert(lseek(inputFile, -1 * BUFFER_SIZE, SEEK_CUR) != -1);
            fileSize -= BUFFER_SIZE;
            bytesRead = read(inputFile, buffer, BUFFER_SIZE);
            fileSize = lseek(inputFile, -1 * BUFFER_SIZE, SEEK_CUR);
        }

        reverseString(buffer, bytesRead);
        write(outputFile, buffer, bytesRead);
        assert(bytesRead != -1);
    }
    close(inputFile);
    close(outputFile);
    return 0;
}