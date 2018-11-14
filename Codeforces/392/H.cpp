#include<iostream>
#include<queue>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

int bfs(map<int,vector<int> > &g , int s, int d, int n)
{
    int dis[n+1];
    for(int i=0; i<=n; i++) dis[i]=-1;
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i];
            if(dis[v]==-1) {
                dis[v] = dis[u]+1;
                if(v==d) return dis[v];
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int t, cs=0;
    cin>>t;
    while(t--) {
        int n,m, u,v;
        cin>>n>>m;

        long long int coin[m+1];
        for(int i=1; i<=m; i++) cin>>coin[i];

        map<int, vector<int> > g;
        for(int i=0; i<n; i++) {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cin>>u>>v;

        int p = bfs(g,u,v, m);
        if(p==-1) cout<<"Case "<<++cs<<": "<<"Path not found\n";
        else if( coin[v] - p >0 ) {
            cout<<"Case "<<++cs<<": "<<coin[v]-p<<"\n";
        }
        else cout<<"Case "<<++cs<<": "<<"Don't travel\n";
    }
    return 0;
}
