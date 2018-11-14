#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    long a[n+1];
    int i;
    for (i=0; i<n; i++) scanf("%d", &a[i]);

    if (n==1) {
        printf("1");
        return 0;
    }
    long sum = 0;


    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {

            sum = a[i] + a[j];

            if ( sum&(sum-1) == 0) {
                break;
            }
        }
    }
}
