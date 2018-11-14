#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
int boom, boomDay;

int bfs( int src, vector<int> g[], int n )
{
    int level[n], total[n];
    boom = 0; boomDay = 0;
    queue<int> q;
    bool vis[n];
    for(int i=0; i<n; i++) {
        vis[i] = false;
        total[i] = 0;
    }
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(vis[v]==false)
            {
                vis[v] = true;
                level[v] = level[u]+1;
                total[level[v]]++;
                q.push(v);
            }
        }

    }
    for(int i=0; i<n; i++)
    {
        if( total[i] > boom ) {
            boom = total[i];
            boomDay = i;
        }
    }
    if(boom==0 && boomDay==0) return -1;
    return 1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w",stdout);

    int n;
    cin>>n;
    vector<int> g[n];
    for(int i=0; i<n; i++)
    {
        int x;
        int u;
        cin>>x;
        while(x--) {
            cin>>u;
            g[i].push_back(u);
        }
    }
    int t, s;
    cin>>t;
    while(t--)
    {
        cin>>s;

        int res = bfs(s, g, n);
        if(res==-1) cout<<"0\n";
        else cout<<boom<<" "<<boomDay<<"\n";
    }
    return 0;
}
