#include<stdio.h>

int a[5];

int make23(int sum, int i, int j)
{
    if(i > 4 || j > 4) return 0;
    if( sum == 23 && i==4 && j==4) return 1;

    make23( sum*a[i], i+1 )
}

int main()
{
    while( scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4] ) )
    {
        if( a[0]==0 ) break;

        int ans = make23(a[0] ,0,0);

        ans? printf("Possible\n"): printf("Impossible\n");

    }

    return 0;
}
