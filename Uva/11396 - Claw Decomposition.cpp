#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

bool claw(vector<int> g[], int n)
{
    int col[n+1];
    for(int i=0; i<=n; i++) col[i] = -1;
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        if(col[i]==-1)
        {
            q.push(i);
            col[i] = 1;
            while(!q.empty())
            {
                int u = q.front(); q.pop();
                for(int i=0; i<g[u].size(); i++)
                {
                    int v = g[u][i];
                    if(col[v]==-1)
                    {
                        (col[u]==1)?col[v]=0: col[v]=1;
                        q.push(v);
                    }
                    else if(col[u]==col[v]) return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);

    int n;
    int u,v;
    while(cin>>n)
    {
        vector<int> g[n+1];
        if(n==0) break;
        while(cin>>u>>v)
        {
            if(u==0 && v==0) break;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool ans = claw( g, n );
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
