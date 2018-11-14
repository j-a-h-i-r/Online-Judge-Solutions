#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs (vector<int>g[], int st )
{
    queue<int>q;
    int tot=1;
    bool vis[1005];
    for(int i=0; i<1005; i++) vis[i]=false;
    q.push(st);
    vis[st]=true;
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i];
            if(vis[v]==false)
            {
                vis[v]=true;
                q.push(v);
                tot++;
            }
        }
    }
    return tot;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<int>g[n+1];

    vector<int>king(k);
    for(int i=0; i<k; i++) cin>>king[i];
    int u,v;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long maxPosEdge = 0;
    long long maxNode = 0;
    long long nodeOfComp = 0;

    for(int i=0; i<k; i++)
    {
        long long numOfNode = (long long)(bfs(g,king[i]) );
        maxNode = max(maxNode, numOfNode);
        maxPosEdge += ((numOfNode)*(numOfNode-1))/2;
        nodeOfComp += numOfNode;
    }
    long long freeNode = n - nodeOfComp;
    maxPosEdge += ((freeNode)*(freeNode-1))/2;
    maxPosEdge += (freeNode*maxNode);
    maxPosEdge -= m;

    cout<<maxPosEdge;

    return 0;
}
