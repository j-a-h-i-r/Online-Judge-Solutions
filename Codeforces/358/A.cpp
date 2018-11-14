#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,m;
    scanf("%ld %ld", &n, &m);

    long mi = min(n,m), mx = max(n,m);
    long long ans = 0;

    for(long i=1; i<=mi; i++)
    {
        ans += (mx+i)/5 - (i/5);
    }

    printf("%lld\n", ans);
}
