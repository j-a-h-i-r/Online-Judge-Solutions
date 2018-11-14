#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int n, m;

void top(vector<int>g[], vector<int>in)
{
    vector<int> vis(n+1, 0);
    queue<int>q;
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0) q.push(i);
    }
    while(!q.empty() )
    {
        int u = q.front(); q.pop();

        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if( vis[v]==0 && --in[v]==0 )
            {
                vis[v] = 1;
                q.push(v);
            }
        }
        cout<<u<<" ";
    }
    cout<<endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;

        vector<int> g[n+1], in(n+1, 0);
        int u, v;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            in[v]++;
            //cout<<u<< "-" << v<<endl;
        }
        top(g, in);
    }
    return 0;
}
