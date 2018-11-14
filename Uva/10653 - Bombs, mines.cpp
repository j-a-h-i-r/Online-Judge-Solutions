#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

static int g[1000][1000];
int r,c;

const int fx[] = { 1,0,-1,0 };
const int fy[] = { 0,1,0,-1 };

int bfs( int sx,int sy, int dx, int dy )
{
    int d[r][c];
    for(int i=0; i<r; i++){
        memset(d[i],-1,sizeof(d[i]));
    }
    queue<int>qx,qy;
    qx.push(sx); qy.push(sy);
    d[sx][sy] = 0;

    while(!qx.empty())
    {
        int ux = qx.front(); qx.pop();
        int uy = qy.front(); qy.pop();

        for(int i=0; i<4; i++)
        {
            int nx = ux + fx[i];
            int ny = uy + fy[i];

            if( nx>=0&&nx<r && ny>=0&&ny<c && g[nx][ny] ==0 && d[nx][ny]==-1 )
            {
                //valid
                d[nx][ny] = d[ux][uy] + 1;
                qx.push(nx);
                qy.push(ny);
                if( nx==dx && ny==dy ) return d[dx][dy];
            }

        }
    }
    return d[dx][dy];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","r", stdout );

    int n, k, m;
    while(cin>>r>>c)
    {
        //cout<<r<<" "<<c<<endl;
        if(r==0 && c==0) break;

        for(int i=0; i<r; i++)
            memset(g[i], 0, sizeof(g[i][0])*c );
            //for(int j=0; j<c; j++) g[i][j] = 0;

        int i;
        cin>>n;
        //cout<<n<<endl;
        while(n--)
        {
            cin>>k>>m;
            //cout<<k<<" "<<m<<endl;
            while(m--)
            {
                cin>>i;
                //cout<<k<<" "<<i<<endl;
                g[k][i] = 1;
            }
        }
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        //cout<<sx<<" "<<sy<<endl;
        //cout<<dx<<" "<<dy<<endl;
        int d = bfs( sx,sy, dx,dy );
        cout<<d<<"\n";
    }
    return 0;
}
