#include<bits/stdc++.h>
using namespace std;

int chemistry[101][101];
int n;
int dp[20][66000];

long re(int f, int m)
{
    //cout<<"M "<<m<<endl;
    if (f<0) return 0;
    if (dp[f][m] != -1) return dp[f][m];
    long ans = 0;
    for (int i=0; i<n; i++) {
        if ( (m & (1<<i)) == 0 ) {
            //cout<<"M<<i "<< (m|(1 <<i )) <<endl;
            ans = max(chemistry[f][i] + re(f-1, m|(1<<i)), ans );
        }
    }
    //cout<<f<<"-"<<m<<"-"<<ans<<endl;

    dp[f][m] = ans;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int cs=1; cs<=t; ++cs) {
        cin>>n;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin>>chemistry[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        long ans = re(n-1, 0);
        cout<<"Case "<<cs<<": "<<ans<<"\n";
    }
    return 0;
}

