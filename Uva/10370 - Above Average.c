#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, ara[110];
        memset(ara, 0, sizeof(ara));
        scanf("%d", &n);
        int i , sum = 0;
        for(i = 0; i<n; i++){
            int e;
            scanf("%d", &e);
            ara[e]++;
            sum += e;
        }
        sum = sum/n;
        int c = 0;

        for(i=sum+1; i<=100; i++){
            c += ara[i];
        }
        printf("%.3lf%%\n", (double)((c*100.0)/n));
    }
}
