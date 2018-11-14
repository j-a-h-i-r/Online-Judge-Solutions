/*
I need to build the graph myself
I have a constraint for edge
If two co-ordinates satisfy this constraint then
There is an edge between them
O(n^2) to build graph
Then BFS
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;

#define INF 20000000

double x[1005], y[1005];
bool hole[1005][1005];
double dis[1005], D;
int sz;

bool check(int i, int j)
{
    double a = x[i] - x[j];
    double b = y[i]  - y[j];
    double d = sqrt( a*a + b*b );
    return ( d<=D );
}

int bfs( )
{
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0; i<sz; i++)
        {
            if(dis[i]==INF && hole[u][i]){
                if(i==1) return dis[u];
                dis[i] = dis[u] + 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);

    char s[30];
    int v, m;
    while(scanf("%d %d",&v,&m))
    {
        if(v==0 && m==0) break;
        D = v*m*60;
        sz = 0;
        getchar();
        while(gets(s)) {
            if( strlen(s) ==0 ) break;
            sscanf(s,"%lf %lf",&x[sz],&y[sz]);
            sz++;
        }
        for(int i=0; i<sz; i++)
        {
            hole[i][i] = true;
            dis[i] = INF;
            for(int j=i+1; j<sz; j++)
            {
                hole[i][j]=hole[j][i]=check(i,j);
            }
        }
        int ans = bfs( );
        if(ans<0) cout<<"No.\n";
        else cout<<"Yes, visiting "<<ans<<" other holes.\n";
    }
    return 0;
}
