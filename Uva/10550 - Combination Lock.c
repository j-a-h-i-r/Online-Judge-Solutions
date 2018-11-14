#include<stdio.h>
int main()
{
    int a,b,c,d;

    scanf("%d%d%d%d", &a,&b,&c,&d);

    while( !(a==0 && b==0 && c==0 && d==0) ){
        int rot1, rot2, rot3;

        if (a<b) rot1 = (a-b+40)*9;
        else rot1 = (a-b) *9;

        if (b<c) rot2 = (c-b)*9;
        else rot2 = (c-b+40)*9;

        if(c<d) rot3 = (c-d+40)*9;
        else rot3 = (c-d)*9;

        int tot = 1080+rot1+rot2+rot3;

        printf("%d\n", tot);

        scanf("%d%d%d%d", &a,&b,&c,&d);
    }
}
