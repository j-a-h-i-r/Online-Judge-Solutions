#include<stdio.h>
#include<stdbool.h>

static bool vis[100001];

int main()
{
    int n,k,i,j;
    int city[n+1];
    long long sum = 0;
    scanf("%d%d", &n,&k);
    scanf("%d", city[1]);
    for(i=2; i<=n; i++) {
        scanf("%d", city[i]);
        sum+=(city[i]*city[i-1]);
    }

    for(i=1; i<=k; i++)
    {
        for(j=1; j<=k-2; j++) {
            if(vis[j] == true) continue;
            sum+= city[j]*city[k];
        }
        for(j=k+2; j<=n; j++) {
            if(vis[j]==true) continue;
            sum+= city[j]*city[k];
        }
        vis[k] = true;
    }

    printf("%I64d\n", sum);
}
