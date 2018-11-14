#include<stdio.h>
int main()
{
    long long int f[100];
    f[1] = 1;
    f[2] = 2;

    int i;

    for(i = 3; i<=90; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }

    int t, cs=0;
    scanf("%d", &t);

    while(t--)
    {
        long long n;
        scanf("%lld", &n);

        for(i=90; i>=1 && f[i] > n ; i--) {}


        printf("Case %d: ", ++cs);

        for( ; i>=1 ; i--)
        {
            if( f[i] <= n ) {
                printf("1");
                n -= f[i];
            }
            else {
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}

