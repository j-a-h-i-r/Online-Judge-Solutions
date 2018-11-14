#include<stdio.h>
#include<string.h>
int kad(int a[], int n)
{
    int i, sum = 0, msum = 0;
    for(i=0; i<n; i++) {
        if( sum+a[i] > 0 ) sum += a[i];
        else sum = 0;
        if(sum>msum) msum = sum;
    }
    return msum;
}

int main()
{
    /*freopen("in.txt", "r", stdin);*/

    int n;

    while( scanf("%d", &n) != EOF ){
        int a[n][n];
        int sub[n];

        int i,j,k,sum, mxsum = -500;

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &a[i][j]);
                /*printf("%d ", a[i][j]);*/
            }
        }
        /*printf("\n");*/

        for(i=0; i<n; i++)
        {
            memset(sub, 0, sizeof(sub));
            for(j=i; j<n; j++)
            {
                for(k=0; k<n; k++) {
                    sub[k] = sub[k] + a[k][j];
                }

                sum = kad( sub , n );
                /*printf("%d\n", sum);*/

                if(sum>mxsum) mxsum = sum;
            }
        }

        printf("%d\n", mxsum);
    }
    return 0;
}
