#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

const long INF = 1e14;

struct node{
    int u, cost;
    node (int a, int b)
    {
        u = a;
        cost = b;
    }
    friend bool operator<(node a, node b)
    {
        return a.cost>b.cost;
    }
};

void print(int arr[], int i )
{
    if(i == 1)
    {
        cout<<1;
        return;
    }
    print(arr, arr[i]);
    cout<<" "<<i;
}

void dijkstra(int src, int des, vector<node> vec[])
{
    bool taken[des+1];
    int path[des+1];
    long dist[des+1];
    for(int i=0; i<=des; i++) {
        dist[i] = INF;
        taken[i] = false;
    }

    priority_queue<node , vector<node> > pq;

    pq.push(node(src, 0));
    dist[1] = 0;

    while( !pq.empty() )
    {
        int u = pq.top().u;
        int c = pq.top().cost;  pq.pop();

        for( int i=0; i<vec[u].size(); i++ )
        {
            int v = vec[u][i].u;
            int w = vec[u][i].cost;

            if( dist[u] + long(w) < dist[v] )
            {
                dist[v] = dist[u] + long(w);
                pq.push( node(v, dist[v]) );
                path[v] = u;
            }
        }
    }
    if(dist[des] == INF) cout<<-1<<"\n";
    else {
        print(path, des);
    }
    cout<<"\n";
    return;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n,m;
    cin>>n>>m;

    vector< node > vec[n+1];

    while(m--)
    {
        int u,v;
        int w;

        cin>>u>>v>>w;

        vec[u].push_back( node(v, w) );
        vec[v].push_back( node(u, w) );
    }

    dijkstra(1, n, vec);

    return 0;
}
