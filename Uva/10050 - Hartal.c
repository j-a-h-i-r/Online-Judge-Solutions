#include<stdio.h>
#include<stdlib.h>

int main()
{
    /*freopen("in.txt", "r", stdin);*/

    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);
        int a[n+1];

        memset(a, 0, sizeof(a));

        int p;

        scanf("%d", &p);

        int d, i;

        while(p--) {
            scanf("%d", &d);

            for(i=d ; i <= n; i+=d ) {
                a[i] = 1;
            }
        }

        int c = 0;

        for(i=1; i<=n; i++) {
            /*printf("%d ", a[i]);*/
            if( i%7==0 || i%7==6 ){

            }
            else if(a[i]) c++;
        }

        printf("%d\n", c);

    }

    return 0;
}
