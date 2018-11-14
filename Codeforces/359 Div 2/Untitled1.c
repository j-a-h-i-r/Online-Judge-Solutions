#include<stdio.h>
int main()
{
    int t, cs=0;
    scanf("%d", &t);
    while(t--)
    {
        int a,b,c,n;
        scanf("%d%d%d%d", &a,&b,&c,&n);

        if( (b-a) == (c-b) ) {
            long term = a + (n-1)*(b-a);
            printf("Case %d: %ld\n", ++cs,  term);
        }
        else printf("Case %d: Error\n", ++cs);
    }

    return 0;
}
