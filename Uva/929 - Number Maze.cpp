#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

#define INF 9999999
int m,n;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

struct node{
    int w, r, c;
    node(int a,int b,int d) {
        w=a; r=b; c=d;
    }
    friend bool operator<(node a, node b ) {
        return a.w > b.w;
    }
};

int dij(int x,int y, short int maze[1000][1000])
{
    priority_queue<node> pq;
    //bool vis[m][n];
    int dis[m][n];

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            //vis[i][j] = false;
            dis[i][j] = INF;
        }
    }
    pq.push( node(0, 0,0));
    dis[0][0] = maze[0][0];

    while(!pq.empty()) {
        node u = pq.top(); pq.pop();
        int ux = u.r, uy = u.c;

        for(int i=0; i<4; i++) {
            int nx = ux+dx[i];
            int ny = uy+dy[i];

            if(nx>=0&&nx<m&&ny>=0&&ny<n) {
                if(dis[ux][uy]+maze[nx][ny] < dis[nx][ny] ) {
                    dis[nx][ny] = dis[ux][uy] + maze[nx][ny];
                    pq.push(node(dis[nx][ny], nx,ny));
                }
            }
            if(nx==x && ny==y) return dis[nx][ny];
        }
    }
    return dis[x][y];
}

int main()
{
    //freopen("in.txt","r",stdin);
    short int maze[1000][1000];
    int t;
    cin>>t;
    while(t--) {
        cin>>m>>n;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) cin>>maze[i][j];
        }
        int ans = dij(m-1,n-1, maze);
        cout<<ans<<"\n";
    }
    return 0;
}
