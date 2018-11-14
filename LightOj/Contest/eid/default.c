#include<stdio.h>
int main()
{
    int n = 10;

    switch(n) {
        case 1:
            printf("one\n");
        case 2:
            printf("two\n");
        case 3:
            printf("three\n");
        case 4:
            printf("four\n");
        case 5:
            printf("five\n");
        default:
            printf("nan");
    }
}
