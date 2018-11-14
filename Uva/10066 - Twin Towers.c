#include<stdio.h>
#include<string.h>

int n,m;
int a[101], b[101];
int dp[101][101];

int max(int x, int y)
{
    return x>y? x : y;
}

int lcs(int i, int j)
{
    if(i==n || j==m) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    {
        return dp[i][j] = 1 + lcs(i+1, j+1);
    }
    else
    {
        int ans1 = lcs(i+1, j);
        int ans2 = lcs(i, j+1);

        return dp[i][j] = max(ans1, ans2);
    }
}

int main()
{
/*    freopen("in.txt", "r", stdin); */
    int num = 0;
    while(scanf("%d%d", &n,&m)==2)
    {
        if( n==0 && m==0) break;

        memset(dp, -1, sizeof dp);

        int i;

        for(i=0; i<n; i++) scanf("%d", &a[i]);
        for(i=0; i<m; i++) scanf("%d", &b[i]);

        printf("Twin Towers #%d\n", ++num);
        printf("Number of Tiles : %d\n\n", lcs(0,0));
    }
    return 0;
}
