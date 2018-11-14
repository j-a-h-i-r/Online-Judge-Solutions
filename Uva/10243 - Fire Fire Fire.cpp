#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int par[1500];
int dp[1500][3];
vector< vector<int> > g;

int cover(int u, int state)
{
    if (g[u].size() == 0) return 1;
    if ( dp[u][state] != -1 ) return dp[u][state];

    int sum = 0, v;

    for (int i=0; i<g[u].size(); ++i) {
        v = g[u][i];
        //cout<<u<<" "<<v<<"\n";

        if (v != par[u]) {
            par[v] = u;

            if (state == 0) {
                sum += cover(v, 1);
            }
            else {
                sum += min( cover(v,1), cover(v,0) );
            }
        }
    }
    return dp[u][state] = sum + state;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    int u, v, k, ans;
    while ( cin>>n ) {
        if (n == 0) break;

        for (int i=0; i<g.size(); i++) g[i].clear();
        g.resize(n+1);
        for (int i=0; i<=n; i++) dp[i][0]=-1, dp[i][1]=-1, dp[i][2]=-1;
        for (int i=0; i<=n; i++) par[i] = -1;

        for (int u=1; u<=n; u++) {
            cin>>k;
            while ( k-- ) {
                cin>>v;
                g[u].push_back(v); //cout<<u<<" pushed\n";
            }
        }

        ans = min( cover(1, 0), cover(1, 1));
        cout<<ans<<"\n";
    }
    return 0;
}
