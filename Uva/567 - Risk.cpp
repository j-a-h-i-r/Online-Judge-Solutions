#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<iomanip>
using namespace std;

int bfs( int start, int dest, vector<int>g[21] )
{
    int dist[21],vis[21];
    for(int i=0; i<21; i++) vis[i] = 0;
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    vis[start] = 1;
    while( !q.empty() )
    {
        int u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if( vis[v]==0 )
            {
                dist[v] = dist[u]+1;
                vis[v] = 1;
                q.push(v);
                if( v==dest ) {
                    q = queue<int>();
                    break;
                }
            }
        }
    }
    return dist[dest];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w", stdout);

    int n, u, v, cs=0, flag = 0;
    while(cin>>n)
    {
        //if(flag) cout<<"\n";
        //flag = 1;

        cout<<"Test Set #"<<++cs<<"\n";

        vector<int>g[21];
        for(int i=0; i<n; i++)
        {
            cin>>u;
            g[1].push_back(u);
            g[u].push_back(1);
        }
        for(int i=2; i<20; i++)
        {
            cin>>n;
            while(n--)
            {
                cin>>u;
                g[i].push_back(u);
                g[u].push_back(i);
            }
        }
        cin>>n;
        while(n--)
        {
            cin>>u>>v;
            int d = bfs( u, v, g );
            cout<<right<<setw(2)<<u<<" to "<<right<<setw(2)<<v<<": "<<d<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
