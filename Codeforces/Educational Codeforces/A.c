#include<stdio.h>
int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);

    printf("%I64d\n", (n/k + 1)*k );

    return 0;
}
