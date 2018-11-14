#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

bool bfs_check(int s,int e, vector<int>g[], int n)
{
    if(s==e) return true;

    bool vis[n+1];
    for(int i=0; i<=n; i++) vis[i] = false;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while( !q.empty(  ) )
    {
        int x = q.front(); q.pop();
        for(int i=0; i<g[x].size(); i++)
        {
            int y = g[x][i];
            if(y==e) return true;
            if( vis[y]==false )
            {
                vis[y]=true;
                q.push(y);
            }
        }
    }
    return false;
}

int main()
{
    bool newLine = false;

    int t;
    scanf("%d", &t);

    getchar();
    getchar();

    char c;
    int u,v, n;

    while(t--)
    {
        if(newLine) printf("\n"); newLine = true;

        char s[100];

        int success = 0, unsuccess = 0;
        scanf("%d", &n);
        getchar();

        vector<int> con[n+1];

        while( fgets(s, 90, stdin) != NULL )
        {
            if(s[0]=='\n') break;
            sscanf(s, "%c %d %d", &c, &u, &v);

            if(c=='c')
            {
                con[u].push_back(v);
                con[v].push_back(u);
            }
            else if(c=='q')
            {
                bool ans = bfs_check(u, v, con, n);
                if(ans==true) success++;
                else unsuccess++;
            }
        }
        printf("%d,%d\n",success,unsuccess);
    }
    return 0;
}
