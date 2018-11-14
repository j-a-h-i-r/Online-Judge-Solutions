#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t, cs = 0;
    long  x1,y1,x2,y2;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%ld%ld%ld%ld", &x1,&y1,&x2,&y2);
        if( labs(y2-y1) == labs(x2-x1) )
        {
            printf("Case %d: 1\n", ++cs);
        }
        else
        {
            if( labs(y1-y2-x2+x1)%2L == 0 )
            {
                printf("Case %d: 2\n", ++cs);
            }
            else printf("Case %d: impossible\n", ++cs);
        }
    }
    return 0;
}
