#include<stdio.h>
int main()
{
    int ara[15];

    int i;

    for(i=0; i<15; i++) ara[i] = i;

    ara[9] = ara[9] + 500;

    for(i=0; i<15; i++) printf("%d ",ara[i]);
}
