#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 99999
int main()
{
    int n;
    cin>>n;
    int g[n+1][n+1], edge[n+1];
    int x;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) g[i][j] = INF;
    }
    for(int i=1; i<=n; i++) g[i][i] = 0;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(i!=x)g[i][x] = 1;
        edge[i] = x;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if( g[i][j] > g[i][k]+g[k][j] )
                {
                    g[i][j] = g[i][k]+g[k][j];
                }
            }
        }
    }

/*
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cout<<g[i][j]<<" ";
        cout<<endl;
    }*/

    int ans = INF;

    int i=1;
    while( i<=n )
    {
        if(i==1)
        {
            for(int j=2; j<=n; j++)
            {
                if( edge[j]==1 )
                {
                    ans = min(ans, g[1][j]+1 );
                }
            }
            i++;
            continue;
        }

        if( g[1][i]==g[i][1] && g[1][i]!=INF )
        {
            ans = min(ans, g[1][i] );
        }
        i++;
    }
    i = 2;
    while(i<=n)
    {
        if(i==4)
        {
            for(int j=1; j<n; j++)
            {
                if( edge[j]==4 )
                {
                    ans = min(ans, g[4][j]+1 );
                }
            }
            i++;
            continue;
        }

        if( g[i][n]==g[n][i] && g[i][n]!=INF )
        {
            ans = min( ans, g[i][n] );
        }
        i++;
    }

    if(ans<INF) cout<<ans;
    else cout<<-1;

    return 0;
}
