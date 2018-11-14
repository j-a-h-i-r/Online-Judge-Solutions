#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<functional>
using namespace std;

const long long INF = 99999999999;

long dist[3001];
int cost[3001][3001];

struct edgeCost {
    int edge, cost;
};
typedef struct edgeCost edgeCost;

class compare {
    public:
    bool operator() (const edgeCost &a, const edgeCost &b) {
        return a.cost<b.cost;
    }
};

void distance(vector<edgeCost> v[ ], edgeCost s)
{
    memset(dist, 63, sizeof dist );

    priority_queue<edgeCost, vector<edgeCost> , compare > q;
    q.push(s);
    int n1 = s.edge;
    dist[n1] = 0;

    while(!q.empty())
    {
        edgeCost node = q.top(); q.pop();

        //cout<< "visiting : " << node<< endl;

        for(int i=0; i < v[node.edge].size(); i++)
        {
            edgeCost nb = v[node.edge][i];
            if( dist[node.edge] + cost[node.edge][nb.edge] < dist[nb.edge] )
            {
                //cout<<nb << " " << cost[node][nb] << endl;

                dist[nb.edge] = dist[node.edge] + cost[node.edge][nb.edge];

                q.push( nb );
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin>>t;
    while(t--)
    {
        memset(cost, 15, sizeof cost);

        vector<edgeCost> adj[3001];
        int n,m;
        cin>>n>>m;
        while(m--)
        {
            int v,u, c;
            cin>>v>>u>>c;

            edgeCost ec1 = {u, c}, ec2 = {v, c};

            adj[v].push_back( ec1 );
            adj[u].push_back( ec2 );

            if(cost[u][v] > c ) {
                cost[u][v] = c;
                cost[v][u] = c;
            }
        }
        int src;
        cin>>src;

        edgeCost s = {src, 0};

        distance(adj, s);

        for(int i=1; i<=n; i++)
        {
            if(i == s.edge) continue;

            if(dist[i] != 1061109567 )
            {
                cout<< dist[i] << " ";
            }
            else cout << "-1 ";
        }

        cout<< endl;
    }
}
