#include<iostream>
#include<vector>
using namespace std;

bool ok;
int cr;

bool dfs(int u, int par, vector<int> g[], const vector<int> &col)
{
    ok = ok&&(col[u]==cr);
    for(auto e: g[u])
    {
        if( e!=par )
        {
            dfs(e, u, g, col);
        }
    }
}

bool check(int u, vector<int> g[], const vector<int>&col)
{
    bool ans = true;
    for(auto e : g[u] )
    {
        cr = col[e];
        ok = true;
        dfs(e , u, g,col);
        ans = ans && ok;
    }
    return ans;
}

int main()
{
    int n, u,v;
    cin>>n;
    vector<int> g[n+1];
    for(int i=1; i<n; i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> col(n+1);
    for(int i=1; i<=n; i++) cin>>col[i];

    int r1=-1, r2=-1;
    for(int i=1; i<=n; i++) {
        for(auto e : g[i])
        {
            if(col[e]!=col[i])
            {
                r1 = e;
                r2 = i;
                i = n+1;
                break;
            }
        }
    }
    if(r1==-1)
    {
        cout<<"YES\n1";
        return 0;
    }

    bool ans1 = check(r1, g, col);
    bool ans2 = check(r2, g, col);

    if(ans1)
    {
        cout<<"YES\n"<<r1;
        return 0;
    }
    else if(ans2) {
        cout<<"YES\n"<<r2;
        return 0;
    }
    else cout<<"NO";
    return 0;
}
