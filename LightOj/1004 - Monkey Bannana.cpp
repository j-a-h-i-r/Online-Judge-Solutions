#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int ara[201][200];
int dp[201][200];
int n;

int maxBanana(int i, int j)
{

    if(j<0 || j>=n || ara[i][j]==-1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    //cout<<i<<" "<<j<<endl;

    if(i>=n-1) {
        return dp[i][j] = ara[i][j] +
        max(maxBanana(i+1,j-1), maxBanana(i+1, j));
    }
    else return dp[i][j] = ara[i][j] + max(maxBanana(i+1,j), maxBanana(i+1, j+1));
}

int main()
{
    //freopen("in.txt","r",stdin);

    int t;
    int cs = 0;
    int x;
    cin>>t;
    while(t--) {

        cin>>n;
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<2*n; i++) {
            for(int j=0; j<n; j++) {
                ara[i][j] = -1;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                cin>>ara[i][j];
            }
        }
        for(int i=n, x=n-1; x>=0; i++, x--) {
            for(int j=0; j<x; j++) {
                cin>>ara[i][j];
            }
        }
        cout<<"Case "<<++cs<<": "<<maxBanana(0, 0)<<endl;
    }
    return 0;
}
