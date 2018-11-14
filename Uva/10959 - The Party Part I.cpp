#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

vector<int> bfs(vector<int>g[], int n)
{
    vector<int> lev(n);
    for(int i=0; i<n; i++) lev[i] = -1;
    queue<int> q;
    q.push(0);
    lev[0] = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(lev[v]==-1)
            {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
    return lev;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int p, d;
    int t;
    bool flag = false;
    cin>>t;
    while(t--)
    {

        cin>>p>>d;
        vector<int> g[p];
        int u, v;
        for(int i=0; i<d; i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> lev(p);
        lev = bfs(g, p);

        if(flag) cout<<"\n"; flag = true;

        for(int i=1; i<p; i++) cout<<lev[i]<<"\n";
    }
    return 0;
}
