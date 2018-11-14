#include<stdio.h>
int main()
{
    int t, c=0;

    scanf("%d", &t);

    while(t--) {
        long long n,m;
        scanf("%lld%lld", &n, &m);

        long long firstNeg = (m*(m+1))/2;
        long long firstPos = firstNeg + (m*m);

        long long ans = (n/(2*m))*(firstPos - firstNeg);

        printf("Case %d: %lld\n", ++c, ans);
    }
    return 0;
}
