#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>

using namespace std;

int xc[] = {1,1,0,-1,-1,-1, 0, 1};
int yc[] = {0,1,1, 1, 0,-1,-1,-1};


int depo( char grid[105][105], queue<pair<int,int> > q, int x, int y ) {
    int c = 0;
    bool vis[x][y];
    memset(vis, false , sizeof vis);

    while( !q.empty() )
    {
        pair<int, int > p = q.front( );
        q.pop( );

        //cout<<p.first<< " "<< p.second<< endl;

        if(vis[p.first][p.second] == false ) {
            vis[p.first][p.second] = true;
            c++;
        }
        else continue;

        int a = p.first, b = p.second;

        queue<pair<int,int> > q2;

        q2.push(make_pair(a,b));

        // ekhon er charpashe 8 bar ghuro.
        // jodi kichu pao. then visited true kore dao
        //

        while( !q2.empty( ) ) {
            p = q2.front( );
            q2.pop();
            a = p.first; b = p.second;

            for(int i=0; i<8; i++) {
                int x1 = a+xc[i], y1 = b+yc[i];
                if( (x1>=0 && x1<x) && (y1>=0 && y1<y)) {
                    if(vis[x1][y1] == false && grid[x1][y1] == '@') {
                        vis[x1][y1] = true;
                        q2.push(make_pair(x1, y1));
                    }
                }
            }
        }
    }

    return c;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int m, n;

    while( cin>>m>>n ) {
        if( !(m || n) ) break;

        pair<int , int > pii;

        char g[105][105];

        queue<pair<int , int > > q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cin>>g[i][j];

                if(g[i][j] == '@') {
                    q.push( make_pair(i,j) );
                }
            }
        }

        cout<<depo(g, q, m, n)<<endl;
    }

    return 0;
}
