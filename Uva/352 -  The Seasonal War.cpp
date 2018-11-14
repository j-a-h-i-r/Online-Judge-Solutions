#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int fx[] = { 1, -1, 0,  0, 1, -1,  1, -1 };
int fy[] = { 0,  0, 1, -1, 1, -1, -1,  1 };

int vis[25][25];

void bfs(int x,int y, int n, char ara[25][25])
{
    queue<int>qx, qy;
    qx.push(x); qy.push(y);
    vis[x][y] = 1;
    while(!qx.empty())
    {
        int ux = qx.front(); qx.pop();
        int uy = qy.front(); qy.pop();

        for(int i=0; i<8; i++)
        {
            int nx = ux + fx[i];
            int ny = uy + fy[i];

            if( nx>=0&&nx<n && ny>=0&&ny<n && vis[nx][ny]==0 &&ara[nx][ny]=='1' )
            {
                // valid move
                qx.push(nx);
                qy.push(ny);
                vis[nx][ny] = 1;
            }
        }
    }
}

int war_eagle( char ara[25][25], int n )
{
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) vis[i][j] = 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if( ara[i][j] == '1' && vis[i][j] == 0 )
            {
                cnt++;
                bfs(i,j, n, ara);
            }
        }
    }
    return cnt;
}

int main()
{
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt","w", stdout);

    int n, nm=0;
    char g[25][25];
    while( scanf("%d", &n) != EOF )
    {
        getchar();
        //cout<<n<<endl;
        int w;
        for(int i=0; i<n; i++)
        {
            scanf("%s",g[i]);
            //for(int j=0; j<n; j++) cout<<g[i][j]<<" ";
            //cout<<endl;
        }
        w = war_eagle(g, n);
        cout<<"Image number "<<++nm<<" contains "<<w<<" war eagles.\n";
    }
    return 0;
}
