#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs(vector<int>g[], int st, int n, bool vis[])
{
    int cnt = 1;
    queue<int> q;
    q.push(st);
    vis[st] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int i=0; i<g[u].size(); i++) {
            int v = g[u][i];

            if (vis[v] == false) {
                vis[v] = true;
                q.push(v);
                ++cnt;
            }
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n, m, x, y;
        cin>>n>>m;

        vector<int> g[n+1];

        for (int i=0; i<m; i++) {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        bool visited[n+1];
        for (int i=0; i<=n; i++) visited[i] = false;

        int ans = 0;

        for (int i=1; i<=n; i++) {
            if ( visited[i] == true ) continue;
            ans = max(ans, bfs(g, i, n, visited));
        }
        cout<<ans<<endl;
    }
    return 0;
}
