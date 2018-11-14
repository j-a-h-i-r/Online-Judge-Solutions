#include<stdio.h>
int main()
{
    int list[12];
    int link[12];
    int START;
    int PTR;

    list[1]=12;list[3]=20;list[4]=10;list[6]=15;list[8]=5;list[9]=25;

    link[1]=9;link[3]=6;link[4]=3; link[6]=1; link[8]=-1; link[9]=8;

    START=4;

    PTR=START; link[1]=9;

    printf("Initial list:\n");
    while(PTR!=-1)
    {
        printf("%d\n",list[PTR]);
        PTR=link[PTR];
    }

    int item = 20;

    START=4;

    PTR=START; link[1]=9;

    while(PTR!=-1)
    {
        if(list[PTR]==item)
        {
            printf("pos = %d\n", PTR);
        }
        PTR=link[PTR];
    }
}
