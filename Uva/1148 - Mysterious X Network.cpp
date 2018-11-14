#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

int bfs(vector<int> v[],int s, int d, int n)
{
    bool vis[n];
    int dis[n];
    for(int i=0; i<n; i++) {
        vis[i] = false;
    }
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s]=true;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            int w = v[u][i];
            if(w==d) {
                return dis[u];
            }
            if(vis[w]==false) {
                dis[w] = dis[u] + 1;
                vis[w] = true;
                q.push(w);
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);

    int t;
    bool line = false;
    cin>>t;
    while(t--)
    {
        int n, u,c,x;
        cin>>n;
        vector<int> v[n];
        for(int i=0; i<n; i++)
        {
            cin>>u>>c;
            while(c--) {
                cin>>x;
                v[u].push_back(x);
                //v[x].push_back(u);
            }
        }
        int s,d;
        cin>>s>>d;
        int ans = bfs(v, s, d, n);

        if(line) cout<<"\n"; line = true;

        cout<<s<< " "<<d<< " "<<ans<<"\n";
    }
    return 0;
}
