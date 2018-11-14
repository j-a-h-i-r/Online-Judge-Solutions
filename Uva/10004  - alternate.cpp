#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

void bfs(int mat[200][]){

}

int main()
{
    int n,e,x,y;
    int edge[200][200];

    while(scanf("%d", &n) && n!=0 ){
        for(int i=0; i<200; i++) memset(edge[i], 0, sizeof(edge[i]));

        scanf("%d", &e);
        while(e--) {
            scanf("%d%d", &x,&y);
            edge[x]=y; edge[y]=x;
        }
    }
}
