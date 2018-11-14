#include<stdio.h>
#include<string.h>

int d[31], v[31], n, cnt = 0, w;
int dp[35][1005], dir[35][1005];

int max(int x, int y)
{
    return x>y? x : y;
}

int get(int i, int time)
{
    if( i==n )
    {
        return 0;
    }

    if(dp[i][time]!=-1) return dp[i][time];

    int ans1 = 0;
    if( time - 3*w*d[i] >= 0)ans1 = v[i] + get(i+1, time-3*w*d[i]);
    int ans2 = get(i+1, time);

    if(ans1 > ans2)
    {
        dir[i][time] = 1;
        return dp[i][time] = ans1;
    }
    else
    {
        dir[i][time] = 2;
        return dp[i][time] = ans2;
    }
}

int path[35];
int idx = 0;

int go(int a, int b)
{
    if( dir[a][b] == -1 ) return 0;

    if( dir[a][b] == 1 )
    {
        path[idx++] = a;
        return 1 + go(a+1, b-3*w*d[a]);
    }
    else return go(a+1, b);
}

int main()
{
    /*freopen("in.txt", "r", stdin);*/

    int t , flag = 0;
    while(scanf("%d%d", &t, &w)==2)
    {
        if(flag == 1) printf("\n");
        else flag = 1;

        cnt = 0;
        memset(dp, -1, sizeof dp);
        memset(dir, -1, sizeof dp);
        int i;
        scanf("%d", &n);

        for(i=0; i<n; i++) scanf("%d%d",&d[i], &v[i]);

        int mx = get(0,t);
        int tot = go(0,t);

        printf("%d\n%d\n", mx, tot);

        for(i=0; i<tot; i++)
        {
            printf("%d %d\n", d[path[i]], v[path[i]]);
        }
        idx = 0;
    }
    return 0;
}
