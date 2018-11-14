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
bool f[100009];
//int path[100001];
//int dist [100001];
void dijkstra(int src, int des, vector< pii > vec[], int dist[], int path[])
{
    memset(f, false, sizeof false);

    priority_queue<pii , vector< pii >, comp > pq;
    pq.push(make_pair(src, 0));
    dist[1] = 0;

    while( !pq.empty() )
    {
        int u = pq.top().first;  pq.pop();

        for( int i=0; i<vec[u].size(); i++ )
        {
            int v = vec[u][i].first;
            int w = vec[u][i].second;

            if( (dist[v] == -1 || (dist[u] + w < dist[v])) )
            {
                dist[v] = dist[u] + w;
                pq.push( pii(v, dist[v]) );
                // ami u diye v te jacchi
                // taile u theke v te path na nicchi
                path[v] = u;
            }
        }
        //f[u] = true;
    }
}

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

int main()
{
    //freopen("in.txt", "r", stdin);

    int n,m;
    cin>>n>>m;
    vector< pii > vec[n+1];
    int path[n+1], dist[n+1];
    memset(dist, -1, sizeof dist);

    while(m--)
    {
        int u,v;
        int w;

        cin>>u>>v>>w;

        vec[u].push_back( make_pair(v, w) );
        vec[v].push_back( make_pair(u, w) );
    }

    dijkstra(1, n, vec, dist, path);


    //for(int i=1; i<=n; i++) cout<<i<< " " << path[i] << " ";
    //cout<<dist[n];
    if( dist[n] == -1 ) cout<<-1<<endl;
    else
    {
        //cout<<"debug" << endl;
        print(path, n);
        cout<<endl;
    }

    return 0;
}
