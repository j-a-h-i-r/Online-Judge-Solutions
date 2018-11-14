#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int **g;
int *size;
int *capacity;
bool *vis;
int *degree;
int n;

bool checkCycle(int u)
{
    vis[u] = true;
    bool value = true;
    //cout<<u<<" "<<degree[u]<<endl;
    if (degree[u] != 2) {
        //cout<<"No cycle"<<endl;
        value = false;
    }
    for(int i=0; i<size[u]; i++) {
        if (vis[g[u][i]] == false) {
            value &= checkCycle(g[u][i]);
        }
    }
    //cout<<"found cycle"<<endl;
    return value;
}
int dfs()
{
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if (vis[i] == false) {
            //cout<<"start"<<endl;
            if (checkCycle(i) == true) cnt++;
        }
    }
    return cnt;
}
int main()
{
    int m;
    int u, v;
    scanf("%d %d", &n, &m);

    g = (int**)malloc((n+1)*sizeof(int*));
    size = (int*) malloc((n+1)*sizeof(int));
    capacity = (int*) malloc((n+1)*sizeof(int));
    degree = (int*) calloc(0, (n+1)*sizeof(int));
    vis = (bool*) calloc(0, (n+1)*sizeof(bool));

    for (int i=0; i<=n; i++) {
        vis[i] = false;
        degree[i] = 0;
        size[i]=0;
        capacity[i]=100;
        g[i] = (int *)malloc(capacity[i] * sizeof(int));
    }
    for (int i=1; i<=m; i++) {
        scanf("%d %d", &u, &v);
        g[u][size[u]++] = v;
        g[v][size[v]++] = u;

        if (capacity[u] - size[u] <= 10) {
            realloc(g[u], capacity[u]*2*sizeof(int));
            capacity[u] = capacity[u]*2;
        }

        if (capacity[v] - size[v] <= 10) {
            realloc(g[v], capacity[v]*2*sizeof(int));
            capacity[v] = capacity[v]*2;
        }

        degree[u]++;
        degree[v]++;
    }

    int ans = dfs( );
    printf("%d\n", ans);
    printf("hello\n");
    for(int i=0; i<=n; i++) free(g[i]);
    free(g);
    free(size);
    free(capacity);
    free(degree);
    free(vis);
    printf("world");

    return 0;
}
