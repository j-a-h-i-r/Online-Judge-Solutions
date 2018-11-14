#include<iostream>
#include<queue>
using namespace std;

void bfs(int s, vector<int> (&g)[101], int n)
{
    bool vis[n+1];
    for(int i=0; i<=n; i++) vis[i] = false;
    queue<int> q;
    q.push( s );
    int tot = 0, u,v;

    while(!q.empty()) {
        u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++) {
            v = g[u][i];
            if( vis[v] == false ) {
                vis[v] = true;
                q.push(v);
                tot++;
            }
        }
    }
    cout<<n-tot;
    for(int i=1; i<=n; i++) {
        if( vis[i] == false ) {
            cout<<" "<<i;
        }
    }
}

int main()
{
    int n, k, u, v;
    while(cin>>n) {
        if(n==0) break;
        vector<int> g[101];
        while(cin>>u) {
            if(u==0) break;

            while(cin>>v) {
                if(v==0) break;
                g[u].push_back(v);
            }
        }
        cin>>k;
        while(k--) {
            cin>>u;
            bfs(u, g, n);
            cout<<"\n";
        }
    }
    return 0;
}
