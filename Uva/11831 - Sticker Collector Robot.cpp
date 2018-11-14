#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w",stdout);

    int n, m, s;
    char grid[101][101];

    while( scanf("%d%d%d", &n, &m, &s) != EOF )
    {
        getchar();
        if(n==0&&m==0&&s==0) break;

        int sx, sy, dx, dy;

        for(int i=0; i<n; i++)
        {
            scanf("%s", grid[i]);
            for(int j=0; j<m; j++)
            {
                char o = grid[i][j];
                if(o=='N'||o=='S'||o=='L'||o=='O')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        //cout<<sx<<" "<<sy<<"\n";
        if(grid[sx][sy]=='N')
        {
            dx=-1;
            dy=0;
        }
        else if(grid[sx][sy]=='S')
        {
            dx=1;
            dy=0;
        }
        else if(grid[sx][sy]=='L')
        {
            dx=0;
            dy=1;
        }
        else if(grid[sx][sy]=='O')
        {
            dx=0;
            dy=-1;
        }
        //cout<<dx<<" "<<dy<<endl;

        int cup=0;
        char c;

        getchar();

        char str[s+1];
        scanf("%s", str);

        for(int i=0; i<s; i++)
        {
            c = str[i];
            if(c=='D')
            {
                if(dx==0)
                {
                    swap(dx, dy);
                }
                else {
                    swap(dx, dy);
                    dy = -dy;
                }
            }
            else if(c=='E')
            {
                if(dx==0)
                {
                    swap(dx,dy);
                    dx = -dx;
                }
                else {
                    swap(dx,dy);
                }
            }
            else if(c=='F')
            {
                sx+=dx;
                sy+=dy;
                if(sx<0||sx>=n || sy<0||sy>=m || grid[sx][sy]=='#')
                {
                    // ignore it
                    // change pos to original
                    sx-=dx;
                    sy-=dy;
                }
                else if( grid[sx][sy] == '*' ) {
                    cup++;
                    grid[sx][sy] = '.';
                }
                //cout<<sx<<" "<<sy<<"\n";
            }
            //cout<<str[i]<<" "<<sx<<" "<<sy<<" "<<dx<<" "<<dy<<"\n";
        }
        //cout<<"\n";
        cout<<cup<<"\n";
    }
    return 0;
}
