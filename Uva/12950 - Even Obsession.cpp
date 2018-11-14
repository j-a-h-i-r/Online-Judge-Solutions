#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

struct node {
    int u;
    int toll;
    node(int _n, int _t)
    {
        u = _n;
        toll = _t;
    }
    friend bool operator <(const node &a, const node &b)
    {
        return a.toll > b.toll;
    }
};

int bfs(vector<node>g[], int n)
{
    int cost[n+1];
    for(int i=0; i<=n; i++) cost[i] = -1;
    priority_queue<node> pq;
    pq.push(node(1,0));
    cost[1] = 0;
    while(!pq.empty())
    {
        int u = pq.top().u; pq.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i].u;
            if( cost[v]== -1 && (g[u][i].toll % 2) ==0  )
            {
                cost[v] = cost[u] + g[u][i].toll;
                pq.push(node(v,cost[v]) );
            }
        }
    }
    return cost[n];
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int c, v;
    int x,y,z;
    while(cin>>c>>v)
    {
        vector<node> g[c+1];
        while(v--)
        {
            cin>>x>>y>>z;
            g[x].push_back( node(y,z) );
            g[y].push_back( node(x,z) );
        }

        int ans = bfs(g, c);

        cout<<ans<<"\n";
    }
    return 0;
}
