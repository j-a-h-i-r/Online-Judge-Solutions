#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int col[201];

int bfs(vector<int> v[]) {
    queue <int>q;

    memset(col, -1, sizeof(col));

    q.push(0);
    col[0] = 1;

    while(!q.empty()){
        int n = q.front(); q.pop();

        for(int i=0; i<v[n].size(); i++) {
            if(col[ v[n][i] ] == -1 ){
                q.push(v[n][i]);
                col[v[n][i]] = 1 - col[n];
            }
            else if (col[v[n][i]] == col[n]) return 0;
        }
    }
    return 1;
}

int main()
{
    int n,e,x,y;

    while(1) {
        vector <int> edge[200];
        scanf("%d", &n);
        if(n==0) break;
        scanf("%d", &e);
        while(e--) {
            scanf("%d%d", &x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }

        if (bfs( edge )==1) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
