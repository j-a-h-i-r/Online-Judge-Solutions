#include<stdio.h>
#include<math.h>
int main()
{
    freopen("in.txt", "r", stdin);

    int t;
    double m,n;

    scanf("%d",&t);

    while(t--){
        scanf("%lf%lf",&m, &n);

        long long int ans = (ceil((m-2.0)/3))*(ceil((n-2.0)/3));

        printf("%lld\n", ans);
    }
}
