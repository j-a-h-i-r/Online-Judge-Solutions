#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%lld", &n) !=EOF && n>0) {
        if(n&1) n = (((n+1)/2)*n) + 1;
        else n = ((n/2)*(n+1)) + 1;

        printf("%lld\n", n);
    }
}
