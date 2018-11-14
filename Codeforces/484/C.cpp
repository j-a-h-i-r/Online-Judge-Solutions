#include<iostream>
#include<vector>
using namespace std;
int cnt = 0;
int dfs(vector<int> g[], int n, int s, bool vis[])
{
    vis[s] = true;
    int sz = 1;
    for (int i=0; i<g[s].size(); ++i) {
        int d = g[s][i];
        if (vis[d] == false) {
            sz += dfs(g, n, d, vis);
        }
    }
    if (sz %2 == 0) {
        // the subtree rooted at s has even size
        cnt++;
    }
    return sz;
}

int main()
{
    int n, u, v;
    cin>>n;
    vector<int> g[n+1];
    bool vis[n+1];
    vis[n] = false;
    for(int i=1; i<n; i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        vis[i] = false;
    }

    if(dfs(g, n, 1, vis) % 2 == 1) {
        cout<<-1;
    }
    else {
        cout<<cnt-1;
    }
}
