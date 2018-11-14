#include<stdio.h>
int main()
{
    int t;
    long long n;

    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &n);

        long long ans;
        if (n%2==0) ans =(n/2)*(n+1);
        else ans = ((n+1)/2)*n;
    }
}
