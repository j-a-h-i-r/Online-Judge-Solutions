#include<iostream>
using namespace std;
int g[200005][1000];
int size[200005];
int capacity[200005];
bool vis[200005];
int degree[200005];
int n;

bool checkCycle(int u)
{
    vis[u] = true;
    bool value = true;
    //cout<<u<<" "<<degree[u]<<endl;
    if (degree[u] != 2) {
        //cout<<"No cycle"<<endl;
        value = false;
    }
    for(int i=0; i<size[u]; i++) {
        if (vis[g[u][i]] == false) {
            value &= checkCycle(g[u][i]);
        }
    }
    //cout<<"found cycle"<<endl;
    return value;
}
int dfs()
{
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if (vis[i] == false) {
            //cout<<"start"<<endl;
            if (checkCycle(i) == true) cnt++;
        }
    }
    return cnt;
}
int main()
{
    int m;
    int u, v;
    cin>>n>>m;
    for (int i=0; i<=n; i++) vis[i] = false, degree[i] = 0, size[i]=0, capacity[i]=1000;
    for (int i=1; i<=m; i++) {
        cin>>u>>v;
        g[u][size[u]++] = v;
        g[v][size[v]++] = u;

        if (capacity[u] - size[u] <= 50) {

        }

        degree[u]++;
        degree[v]++;
    }

    int ans = dfs( );
    cout<<ans;
}
