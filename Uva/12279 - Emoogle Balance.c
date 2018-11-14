#include<stdio.h>
int main()
{
    int t, c=0;

    while(scanf("%d", &t) == 1)
    {
        if(t == 0) break;

        int tr = 0, given = 0, x;

        while(t--)
        {
            scanf("%d", &x);

            (x)? tr++: given++;
        }

        printf("Case %d: %d\n", ++c, tr-given);
    }

    return 0;
}
