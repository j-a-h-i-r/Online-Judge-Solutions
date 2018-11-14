#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int bfs(vector<int>g[], int n )
{
    int col[n], one=0, zero=0, mn = 0;
    for(int i=0; i<n; i++) col[i] = -1;
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if( col[i] == -1 )
        {
            one = 0; zero = 0;
            q.push(i);
            col[i] = 1; one++;
            while(!q.empty())
            {
                int u = q.front(); q.pop();
                for(int i=0; i<g[u].size(); i++)
                {
                    int v = g[u][i];
                    if(col[v]==-1)
                    {
                        (col[u]==1)? col[v]=0: col[v]=1;
                        (col[u]==1)? zero++: one++;
                        q.push(v);
                    }
                    else if( col[u]==col[v] ) return -1;
                }
            }
            int val = min(zero, one);
            if(val==0)
            {
                // er maane sob node ei guard bosaite hoise
                mn++;
            }
            else mn += val;
        }
    }
    return mn;
}

int main( )
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    while(t--)
    {
        int v, e;
        cin>>v>>e;
        vector<int> g[v];
        int x,y;

        while(e--)
        {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        } // graph built

        int ans = bfs( g, v );

        cout<<ans<<"\n";
    }
    return 0;
}
