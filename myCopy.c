#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
// main function for copying content of one file to another
int main(int argc, char *argv[])
{
     // read the data in a.txt to buffer varriable
    char b[1024];
    long int n;
    // file variables
    int file1, file2;
    // check the number of arguments
    if(argc!=3)
    {
       perror("Invalid number of arguments");
       exit(1);
    }
    // check if files are read or created
    if(((file1 = open(argv[1], O_RDONLY)) == -1 || ((file2=open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0600))== 1)))
    {
       perror("Error: Problem in accessing or creating the files");
       exit(1);
    }
    // read the file from a.txt
    while((n=read(file1, b, 1024))>0)
    {
        // write the data to b.txt
        if(write(file2, b, n)!=n)
        {
           perror("Error in writing");
           exit(3);
        }
// if nothing is read from the file
        if(n==-1)
        {
           perror("Error in reading");
           exit(2);
        }
    }
    //printf("Successfully Copied");
    // close the file variables
    close(file1);
    close(file2);
    exit(0);
}