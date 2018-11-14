#include<stdio.h>
int main()
{
    /*freopen("in.txt", "r", stdin);*/

    int n,b,h,w;
    while(scanf("%d%d%d%d",&n,&b,&h,&w)!=EOF)
    {
        int cost = 3000000;
        int i, j;

        for(i=1; i<=h; i++)
        {
            int price, a, possible = 0;
            scanf("%d", &price);

            for(j=1; j<=w; j++)
            {
                scanf("%d",&a);
                if(a>=n) possible = 1;
            }
            if( possible ) {
                if(n*price < cost) cost = n*price;
            }
        }

        if(cost<=b) printf("%d\n", cost);
        else printf("stay home\n");
    }
    return 0;
}
