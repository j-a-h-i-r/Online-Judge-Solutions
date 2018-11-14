#include<iostream>
#include<cstring>
using namespace std;

static long long dp[25][10000];

long long call(long long i, long long n)
{
    if( n == 0 ) {
        return 1;
    }
    if( n - i*i*i >= 0 ) {
        if(dp[i][n]!=-1) return dp[i][n];

        long long ret=0, ret2=0;
        ret = call(i, n-i*i*i);
        ret2 = call(i+1, n);

        return dp[i][n]=ret+ret2;
    }
    else return 0;
}

int main()
{
    int n=9999;
    while(cin>>n) {
        memset(dp, -1, sizeof(dp));
        cout<<call(1, (long long)n)<<"\n";
    }
    return 0;
}
