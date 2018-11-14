#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int pos = 0, n;

int mapped(map<int, int>&mp, int d)
{
    if( mp.find(d) == mp.end() )
    {
        mp[d] = pos++;
        return pos-1;
    }
    return mp[d];
}

int bfs( int src, int ttl, vector<int>g[] )
{
    if(ttl == 0) return pos-1;

    queue<int> q;
    int vis[pos], dist[pos], totVis = 1;
    for(int i=0; i<pos; i++)
    {
        vis[i] = 0;
    }
    vis[src] = 1;
    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if( vis[v] == 0 )
            {
                vis[v] = 1;
                dist[v] = dist[u]+1;

                //cout<<rmp[v]<<" "<<dist[v]<<endl;

                if(dist[v]<=ttl) {
                    //q.push(v);
                    totVis++;
                }
                q.push(v);
            }
        }
    }
    return pos-totVis;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt", "w", stdout);
    int cs = 0;
    while( cin>>n )
    {
        //cout<<n<<endl;
        if(n==0) break;
        pos = 0;
        map<int, int> mp;
        int u,v;
        vector<int>g[31];
        for(int i=0; i<n; i++)
        {
            cin>>u>>v;

            //cout<<u<<" "<<v<<"   ";

            u = mapped(mp, u);
            v = mapped(mp, v);

            //cout<<u<<" "<<v<<endl;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        while(cin>>u>>v)
        {

            if(u==0 && v==0) break;

            if( mp.find(u) == mp.end() ) {
                //cout<<cs+1<<" "<<u<< mp[u]<<endl;
                cout<<"Case "<<++cs<<": "<<pos<<" nodes not reachable from node "<<u<<" with TTL = "<<v<<".\n";
                continue;
            }
            int unVisited = bfs(mp[u], v, g);

            cout<<"Case "<<++cs<<": "<<unVisited<<" nodes not reachable from node "<<u<<" with TTL = "<<v<<".\n";
        }
    }
    return 0;
}
