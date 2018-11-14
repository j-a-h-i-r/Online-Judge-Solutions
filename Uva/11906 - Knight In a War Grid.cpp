#include<iostream>
#include<queue>
#include<cstdio>
#include<map>
using namespace std;

int fx[] = {1,1,-1,-1};
int fy[] = {1,-1,1,-1};
int dx[8], dy[8];

int r, c;

struct cnt{
    int even, odd;
    cnt(int e, int o){
        even = e; odd = o;
    }
};

cnt traverse (int ara[100][100])
{
    cnt tot(0,0);
    bool vis[r][c], temp[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) vis[i][j] = false;
    }
    queue<int>qx, qy;
    qx.push(0);
    qy.push(0);
    vis[0][0] = true;
    while(!qx.empty())
    {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) temp[i][j] = false;
        }
        int k=0;
        int ux = qx.front(); qx.pop();
        int uy = qy.front(); qy.pop();

        for(int i=0; i<8; i++)
        {
            int nx = ux+dx[i];
            int ny = uy+dy[i];

            if(nx>=0&&nx<r&&ny>=0&&ny<c&&ara[nx][ny]==1)
            {
                if(temp[nx][ny]==false) {
                    k++;
                    temp[nx][ny] = true;
                }

                if(vis[nx][ny]==false)
                {
                    qx.push(nx);
                    qy.push(ny);
                    vis[nx][ny]=true;
                }
            }
        }
        //cout<<ux<<" "<<uy<<" "<<k<<endl;
        if(k%2==0) tot.even++;
        else tot.odd++;
    }
    return tot;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int ara[100][100];
    int t, cs=0;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>r>>c>>m>>n;

        for(int i=0; i<4; i++){
            dx[i] = fx[i]*m;
            dy[i] = fy[i]*n;
        }
        for(int i=4; i<8; i++){
            dx[i] = fx[i-4]*n;
            dy[i] = fy[i-4]*m;
        }
        /*for(int i=0; i<8; i++)
        {
            cout<<dy[i]<<" ";
        }*/

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                ara[i][j] = 1;
            }
        }
        int w, x,y;
        cin>>w;
        while(w--)
        {
            cin>>x>>y;
            ara[x][y] = 0;
        }

        cnt ans = traverse(ara);

        cout<<"Case "<<++cs<<": ";
        cout<<ans.even<<" "<<ans.odd<<"\n";
    }
    return 0;
}
