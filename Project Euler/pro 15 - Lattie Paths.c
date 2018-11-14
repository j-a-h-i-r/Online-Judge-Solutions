/**
Classic DP problem;
Two ways to go from current point
Go right ( i, j+1 )  or   down  ( i+1, j )
save their total in an array;
**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long total[21][21];
int m, n;

long long grid(int x, int y )
{

    if(x==m && y==n)
    {
        return 1LL;
    }

    if(x>m || y>m) return 0LL;

    if( total[x][y] == -1 )
    {
        total[x][y] = grid(x+1, y) + grid(x, y+1);
        return total[x][y];
    }
    else return total[x][y];
}

int main()
{

    scanf("%d%d", &m, &n);

    memset(total, -1, sizeof(total));

    printf("%lld\n", grid(0, 0));

    return 0;
}
