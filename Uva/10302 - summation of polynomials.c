#include<stdio.h>
int main()
{
    long long int n;

    while(scanf("%lld", &n)!=EOF) {
        if(n%2 == 0) n = (n/2)*(n+1);
        else n = n*((n+1)/2);

        printf("%lld\n", n*n);
    }
    return 0;
}
