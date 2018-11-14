#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>

#define pii pair<int,int>

using namespace std;

class comp
{
public:
    bool operator() (pii a, pii b)
    {
        return a.second > b.second;
    }
};

int dijkstra(int src, int des, vector< pii > vec[], int dist[])
{
    int first = -1, second = -1;
    priority_queue<pii, vector< pii >, comp > pq;
    pq.push(make_pair(src, 0));
    dist[src] = 0;

    while( !pq.empty() )
    {
        int u = pq.top().first;
        pq.pop();

        for( int i=0; i<vec[u].size(); i++ )
        {
            int v = vec[u][i].first;
            int w = vec[u][i].second;

            if( (dist[v] == -1 || (dist[u] + w < dist[v])) )
            {
                dist[v] = dist[u] + w;
                pq.push( pii(v, dist[v]) );
                //path[v] = u;

                if(v==des)
                {
                    if( dist[u] > first )
                    {
                        second = first;
                        first = dist[u];
                    }
                }
            }
        }
    }
    return second>=0? second: first;
}


int main()
{
    freopen("in.txt", "r", stdin);

    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector< pii > vec[n+1];
        int dist[n+1];
        memset(dist, -1, sizeof dist);

        while(m--)
        {
            int u,v;
            int w;

            cin>>u>>v>>w;

            vec[u].push_back( make_pair(v, w) );
            vec[v].push_back( make_pair(u, w) );
        }

        cout<<dijkstra(1, n, vec, dist)<<endl;
    }

    return 0;
}


