#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

bool vis[150005];

int bfs(int x, vector<int>g[], int n)
{
    //for(int i=0; i<=n ;i++) vis[i] = false;
    queue<int> q;
    int cnt = 1;
    q.push(x);
    vis[x] = true;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if(vis[v]==false) {
                vis[v]=true;
                //cout<<"v "<<v<<endl;
                q.push(v);
                cnt++;
            }
        }
    }
    return cnt;

}

int main()
{
    //freopen("in.txt","r",stdin);

    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    int u,v;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0; i<=n; i++) vis[i] = false;
    long long node, toted=0;
    for(int i=1; i<=n; i++) {
        if(vis[i]==false) {
            node = bfs(i, g, n);
            //cout<<i<<" "<<node<<endl;
            toted += (node*(node-1))/2;
        }
    }
    //cout<<toted<<endl;
    if(toted==m) {
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}
