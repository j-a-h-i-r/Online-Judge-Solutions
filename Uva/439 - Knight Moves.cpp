#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int fx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int fy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs( int sx, int sy, int dx, int dy )
{
    int d[9][9];
    memset(d,-1,sizeof(d));
    queue<int>qx,qy;
    qx.push(sx); qy.push(sy);
    d[sx][sy]=0;
    while(!qx.empty())
    {
        int ux=qx.front(), uy=qy.front();
        qx.pop(); qy.pop();
        for(int i=0; i<8; i++)
        {
            // knight moves
            int nx = ux + fx[i];
            int ny = uy + fy[i];

            if(nx>=1&&nx<9 && ny>=1&&ny<9&&d[nx][ny]==-1)
            {
                d[nx][ny] = d[ux][uy] + 1;
                qx.push(nx);
                qy.push(ny);

                if(nx==dx && ny==dy) return d[nx][ny];
            }
        }
    }
    return d[dx][dy];
}

int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        int sy = a[1]-'0', dy = b[1]-'0';
        int sx = a[0]-'a'+1, dx = b[0]-'a'+1;
        //cout<<sx<<" "<<sy<<"\n";
        //cout<<dx<<" "<<dy<<"\n";

        int moves = bfs(sx,sy, dx,dy);
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<moves<<" knight moves.\n";
    }
    return 0;
}
