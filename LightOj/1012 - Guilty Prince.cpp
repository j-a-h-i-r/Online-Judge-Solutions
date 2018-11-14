#include<cstdio>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;

int bfs(char a[][22], int x, int y, int lx, int ly){

    int fx[] = {0, 1, 0, -1};
    int fy[] = {1, 0, -1, 0};

    int path = 1;

    queue<pii> q;

    q.push(pii(x,y));

    while(!q.empty()){
        pii top = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = top.first + fx[i];
            int ny = top.second + fy[i];

            if(nx>=0 && nx<ly && ny>=0 && ny<lx
               && a[nx][ny]=='.'){
                   a[nx][ny]='#';
                   q.push(pii(nx,ny));
                   path++;
               }
        }
    }
    return path;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t, c=0;

    scanf("%d", &t);

    while(t--){
        int w, h, sx, sy;
        char swamp[22][22];
        char line[22];

        scanf("%d%d", &w, &h);

        for(int i=0; i<h; i++){
            scanf("%s", line);
            for(int j=0; j<w; j++){
                swamp[i][j] = line[j];

                if(swamp[i][j]=='@') {
                    sx = i;
                    sy = j;
                    //printf("%d  %d\n", sx,sy);
                }
            }
        }

        int ans = bfs(swamp, sx, sy, w, h);

        printf("Case %d: %d\n",++c, ans);
    }
}
