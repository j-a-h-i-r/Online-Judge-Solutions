#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

queue<int> q;

int bfs( vector<int> a[], int s) {

    int vis[20005], f[2];
    f[0]=0; f[1]=0;
    memset(vis, -1, sizeof(vis));

    f[0]++;
    vis[s] = 0;

    while(!q.empty()){
        int n = q.front(); q.pop();

        //printf("n=%d s=%d\n", n, a[n].size());

        for(int i=0; i<a[n].size(); i++) {
            printf("n = %d ", n);
            if(vis[a[n][i]]== -1 ){
                q.push(a[n][i]);
                vis[a[n][i]] = 1 - vis[n];
                f[vis[a[n][i]]]++;
        printf("%d ", a[n][i]);
            }
        }
    }

    if(f[0]<f[1]) return f[1];
    else return f[0];

}

int main()
{
    freopen("in.txt", "r", stdin);

    int t,n,x,y, c=0;
    vector <int>  v[20005];

    scanf("%d", &t);

    while(t--) {

        scanf("%d", &n);

        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
        q.push(x);
        q.push(y);
        int src = x;

        n--;

        while(n--) {
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
            q.push(x);
            q.push(y);
        }


        int ans = bfs(v, src);

        printf("Case %d: %d\n",++c,  ans);

    }
}
