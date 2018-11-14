#include<bits/stdc++.h>
static bool vis[100001];

int main()
{
    //freopen("in.txt","r", stdin);
    int n,k,c,i,j;

    scanf("%d %d", &n,&c);

    int city[n+1];
    long long sum = 0;

    scanf("%d", &city[1]);
    for(i=2; i<=n; i++) {
        scanf("%d", &city[i]);
        sum += (city[i]*city[i-1]);
    }

    sum += city[1]*city[n];

    for(i=1; i<=c; i++)
    {
        scanf("%d", &k);
        for(j=1; j<=k-2; j++) {
            if(vis[j] == true) continue;
            sum += city[j]*city[k];
        }
        for(j=k+2; j<=n; j++) {
            if(vis[j]==true) continue;
            sum += city[j]*city[k];
        }

        if(k==1) sum -= city[1]*city[n];

        vis[k] = true;

    }

    printf("%I64d\n", sum);
}
