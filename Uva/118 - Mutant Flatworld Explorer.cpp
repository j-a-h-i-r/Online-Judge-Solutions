#include<iostream>
#include<cstdio>
using namespace std;

char orient(int x, int y)
{
    //cout<<"xy "<<x<<" "<<y<<"\n";
    if(x==0&&y==1) return 'N';
    if(x==0&&y==-1) return 'S';
    if(x==1&&y==0) return 'E';
    if(x==-1&&y==0) return 'W';
}

int main()
{
    //freopen("in.txt","r", stdin);
    int x, y;
    bool lost[55][55], loss;
    for(int i=0; i<55; i++)
    {
        for(int j=0; j<55; j++) lost[i][j] = false;
    }

    scanf("%d%d", &x, &y);

    int sx, sy, dx, dy;
    char dir;
    while( scanf("%d %d %c", &sx, &sy, &dir)!=EOF )
    {
        loss = false;
        //cout<<sx<<sy<<dir<<"\n";

        if(dir=='N') { dx=0; dy=1; }
        else if(dir=='S') { dx=0; dy=-1; }
        else if(dir=='E') { dx=1; dy=0; }
        else if(dir=='W') { dx=-1; dy=0; }

        char s[110];
        scanf("%s", s);

        for(int i=0; s[i]!='\0'; i++)
        {
            if(s[i]=='F'){
                sx+=dx; sy+=dy;
                if(sx<0||sx>x || sy<0||sy>y) {
                    if( lost[sx-dx][sy-dy]==true) {
                        sx-=dx; sy-=dy;
                        continue;
                    }
                    else {
                        loss = true;
                        sx-=dx; sy-=dy;
                        lost[sx][sy] = true;
                        break;
                    }
                }
            }
            else if(s[i]=='R'){
                if(dx==0&&dy==1) {dx=1; dy=0;}
                else if(dx==0&&dy==-1) {dx=-1; dy=0;}
                else if(dx==1&&dy==0) {dx=0; dy=-1;}
                else if(dx==-1&&dy==0) {dx=0; dy=1;}
            }
            else if(s[i]=='L'){
                if(dx==0&&dy==1) {dx=-1; dy=0;}
                else if(dx==0&&dy==-1) {dx=1; dy=0;}
                else if(dx==1&&dy==0) {dx=0; dy=1;}
                else if(dx==-1&&dy==0) {dx=0; dy=-1;}
            }
        }
        cout<<sx<<" "<<sy<<" "<<orient(dx,dy);
        if(loss==true) cout<<" LOST";
        cout<<"\n";
    }
    return 0;
}
