#include<stdio.h>
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long int m,n;

    while(scanf("%ld%ld", &n, &m)) {
        if(m==0 && n==0) break;

        int p[102], i;
        for (i=0; i<102; i++) p[i] = i;

        if(m > n-m) {
            i = m+1;
        }
        else i = (n-m)+1;

        int j, flag = 0, k;
        long int denom = 1;

       /* for(j = n-i+1; j >= 2; j--) {
            for(k = n; k>=i; k--) {

                //printf("k = %d   p[k] = %d\n", k, p[k]);

                if(p[k]%j==0) {
                    p[k] = p[k]/j;

                    flag = 1;

                    //printf("%d divide\n", j);

                    break;
                }
            }

            if (flag == 0) denom = denom*j;
            flag = 0;

            //if(flag==0) printf("%d does not divide\n", j);
            //flag = 0;
        }
        */

        for(k = i; k<=n; k++) {
            product = product*p[k];
            for(j = n-i+1; j >= 2; j--) {
                if( )
            }
        }

        long int product = 1;
        for(i; i<=n; i++) {
            //printf("%d %d\n", i, p[i]);
            product = product*p[i];
        }

        product = product/denom;

        printf("%d things taken %d at a time is %ld exactly.\n", n, m, product);
    }
}
