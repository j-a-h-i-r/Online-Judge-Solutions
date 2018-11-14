#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

#define INF 999999

struct node {
    int u, cost;
    node(int _u, int c)
    {
        u = _u;
        cost = c;
    }
    friend bool operator<(node a, node b)
    {
        return a.cost > b.cost;
    }
};

int dijk(vector<node> g[], int e, int n, int time)
{
    int tot = 0;
    priority_queue<node, vector<node> > pq;
    int dist[n+1];
    for(int i=0; i<=n; i++) dist[i] = INF;

    pq.push( node(e,0) );
    dist[e] = 0;
    while(!pq.empty())
    {
        node u = pq.top(); pq.pop();
        int un = u.u;
        for(int i=0; i<g[un].size(); i++ )
        {
            node v = g[un][i];
            if( dist[un] + v.cost < dist[v.u] )
            {
                dist[v.u] = dist[un] + v.cost;
                pq.push( node( v.u, dist[v.u] ) );
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(dist[i]<=time) tot++;
    }
    return tot;
}

int main()
{
    bool line = false;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,e,t,m, tm;
    int x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>n>>e>>tm>>m;
        vector<node> g[n+1];
        while( m-- )
        {
            cin>>x>>y>>z;
            g[y].push_back( node(x,z) );
        }

        int ans = dijk( g, e, n, tm);

        if(line) cout<<"\n"; line = true;
        cout<<ans<<"\n";
    }
    return 0;
}
