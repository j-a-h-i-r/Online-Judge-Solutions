#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

int bfs(int sx,int sy, char ara[30][30])
{
    int dis[30][30];
    for (int i=0; i<30; i++) {
        for (int j=0; j<30; j++) dis[i][j] = -1;
    }
    queue<int> qx, qy;
    qx.push(sx); qy.push(sy);
    dis[sx][sy] = 0;
    while(!qx.empty()) {
        int ux = qx.front();    qx.pop();
        int uy = qy.front();    qy.pop();
        for (int i=0; i<4; i++) {
            int nx = ux + fx[i];
            int ny = uy + fy[i];

            if (ara[nx][ny]!='#'&&ara[nx][ny]!='m'&&dis[nx][ny]==-1) {
                dis[nx][ny] = dis[ux][uy] + 1;
                qx.push(nx);
                qy.push(ny);
                //cout<<"d "<<dis[nx][ny]<<endl;
                if (ara[nx][ny]=='h') return dis[nx][ny];
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t, cs=0;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        char ara[30][30];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>ara[i][j];
                //cout<<ara[i][j];
            }
            //cout<<endl;
        }
        int ans = -2;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(ara[i][j]=='a'||ara[i][j]=='b'
                   ||ara[i][j]=='c')
                {
                    ans = max(ans, bfs(i,j,ara) );
                }
            }
        }
        cout<<"Case "<<++cs<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
