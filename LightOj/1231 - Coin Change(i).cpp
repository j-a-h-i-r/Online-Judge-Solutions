#include<bits/stdc++.h>
using namespace std;

long long coin[101];
long long amount[101];

long long mod = 100000007;

long long dp[51][21][1001];

long long ways(long long i, long long taken, long long k)
{
    if(i==-1 || k <0) return 0;
    if(k==0) return 1;

    if(dp[i][taken][k]!=-1) return dp[i][taken][k];

    long long ret = 0;

    if(taken>0) ret += ways(i, taken-1, k-coin[i] );
    if(ret>mod) ret -= mod;

    ret += ways(i-1, amount[i-1], k );
    if(ret>mod) ret-=mod;

    dp[i][taken][k] = ret;

    return dp[i][taken][k];

}

int main()
{
    //freopen("in.txt", "r", stdin);
    long long t, k, n;
    int cs=0;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld%lld", &n, &k);

        for(int i=0; i<n; i++) scanf("%lld",  &coin[i]);
        for(int i=0; i<n; i++) scanf("%lld", &amount[i]);

        memset(dp, -1, sizeof dp);

        printf("Case %d: %lld\n", ++cs, ways(n-1, amount[n-1], k));
    }
    return 0;
}
