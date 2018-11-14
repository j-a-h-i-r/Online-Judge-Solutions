#include<stdio.h>
int main(int argc, char *argv[])
{
    printf("%d\n", argc);
    //printf("%s\n", argv);

    char str[100];
    int move;

    sscanf(argv[1], "%s", str);
    sscanf(argv[2], "%d", &move );

    printf("string to change: %s\n", str);
    printf("move by: %d\n", move);



    return 0;
}
