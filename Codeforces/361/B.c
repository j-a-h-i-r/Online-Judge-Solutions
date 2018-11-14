#include<stdio.h>

static int sh[200002];
static int dp[200002];

int min( int i )
{
    //printf("i = %d sh[i] = %d\n", i, sh[i]);

    if (i==1) return 0;

    if ( dp[i] == 0 ) {

        if( sh[i] == 0 || i == sh[i] ) {
            dp[i] = min( i-1 ) + 1;
        }
        else dp[i] = min( sh[i] ) + 1;

        return dp[i];
    }
    else return dp[i];
}

int main ( )
{
    int n, i = 1;
    scanf("%d", &n);

    int a[n+1];

    for(i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);

        if( sh[ a[i] ] == 0 ) sh[ a[i] ] = i;

        printf("%d ", min( i ) );
    }

    return 0;
}
