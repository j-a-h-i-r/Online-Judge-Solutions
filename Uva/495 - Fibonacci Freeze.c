#include<stdio.h>
int main()
{
    long long f[5001];
    f[0] = 0;
    f[1] = 1;
    int i;
    for(i=2; i<=5000; i++)
    {
        f[i] = f[i-1] + f[i-2];
        printf("%lld ",f[i]);
    }
}
