#include<iostream>
#include<vector>
#include<queue>
using namespace std;

long long get(vector<int>g[], int x, int y, int n)
{
    bool vis[n+1], vis2[n+1], vis3[n+1];
    int par[n+1];
    for(int i=0; i<=n; i++) {
        vis[i] = false;
        vis2[i] = false;
        par[i] = -1;
        vis3[i] = false;
    }
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if (vis[v] == false) {
                vis[v] = true;
                q.push(v);
                par[v] = u;
                if (v == y) {
                    q = queue<int>();
                    break;
                }
            }
        }
    }
    vis3[par[y]] = true;
    int z = y;
    while(par[z] != x) {
        z = par[z];
    }
    vis2[z] = true;

    long long cnt1 = 0, cnt2 = 0;

    queue<int> q1;
    q1.push(x);
    vis2[x] = true;
    while(!q1.empty()) {
        int u = q1.front(); q1.pop();
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if (vis2[v] == false) {
                vis2[v] = true;
                q1.push(v);
                cnt1++;
            }
        }
    }

    queue<int> q2;
    q2.push(y);
    vis3[y] = true;
    while(!q2.empty()) {
        int u = q2.front(); q2.pop();
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if (vis3[v] == false) {
                vis3[v] = true;
                q2.push(v);
                cnt2++;
            }
        }
    }
    long long ln = n;
    return ln*(ln-1) - ((cnt1+1) * (cnt2+1));
}

int main()
{
    int n, x, y;
    int u, v;
    cin>>n>>x>>y;
    vector<int> g[n+1];

    for(int i=0; i<n-1; i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long ans = get(g, x, y, n);
    cout<<ans;

    return 0;
}
