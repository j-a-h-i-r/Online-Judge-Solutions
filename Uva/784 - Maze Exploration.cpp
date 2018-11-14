#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int fx[] = {1,0,-1,0};
int fy[] = {0,1,0,-1};

void bfs(char a[][90], int sx, int sy)
{
    queue<int>qx, qy;
    qx.push(sx); qy.push(sy);
    a[sx][sy] = '#';
    while(!qx.empty())
    {
        int ux = qx.front(); qx.pop();
        int uy = qy.front(); qy.pop();

        for(int i=0; i<4; i++)
        {
            int nx = ux + fx[i];
            int ny = uy + fy[i];

            if( a[nx][ny] == ' ' )
            {
                a[nx][ny] = '#';
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        char s[35][90];
        int ln = 0, sx,sy;
        while( fgets(s[ln], 85,  stdin) )
        {
            if(s[ln][0]=='_') {
                ln++;
                break;
            }
            //cout<<s[ln];
            for(int i=0; s[ln][i]!='\n'&&s[ln][i]!='\0'; i++)
            {
                if(s[ln][i] == '*')
                {
                    sx = ln;
                    sy = i;
                }
            }
            ln++;
        }
        bfs(s, sx, sy);

        for(int i=0; i<ln; i++) cout<<s[i];
    }
    return 0;
}
