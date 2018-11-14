#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<windows.h>
int main()
{
    int i=0;
    while ( i<2 ) {
        printf("hello\n");
        CreateProcess(NULL, NULL, NULL, NULL, NULL);
        printf("hello\n");
        i++;
    }
}
