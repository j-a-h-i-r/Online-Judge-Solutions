#include<stdio.h>

int main()
{
    int n, i, j ,flag = 0;
    scanf("%d", &n);

    long long ara[101];

    for(i=0; i<n; i++) scanf("%I64d", &ara[i]);

    for(i=0; i<n-1; i++) {
            //flag = 0;
        for(j=0; j<n-i-1; j++ ) {
            if( ara[j] > ara[j+1] ) {
                flag = 1;
                long long t = ara[j];
                ara[j] = ara[j+1];
                ara[j+1] = t;

                printf("%d %d\n", j+1, j+2);
            }
        }
        //if (flag == 0) break;

        if(flag == 0) printf("\n");
    }
    return 0;
}
