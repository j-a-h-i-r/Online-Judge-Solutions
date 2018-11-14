#include<stdio.h>
int main()
{
    int n, set = 0;

    while(scanf("%d", &n) && n!=0) {
        set++;
        int a[60], i, sum = 0, h = 0;
        for(i=0; i<n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int avg = sum/n;
        for(i=0; i<n; i++) {
            if(a[i]>avg) {
                h = h + (a[i] - avg);
            }
        }
        printf("Set #%d\n", set);
        printf("The minimum number of moves is %d.\n\n", h);
    }
    return 0;
}
