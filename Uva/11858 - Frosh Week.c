#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        int a[n], i, count = 0, flag = 0, j;
        for(i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        a[i] = '\0';
        int lastSwap = n-1;

        for(i=1; i<n; i++){
            int curSwap = -1;
            for(j=0; j<lastSwap ; j++) {
                if(a[j]>a[j+1]) {
                    int t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                    count++;
                    flag = 1;
                    curSwap = j;
                }
            }
            if(flag == 0) break;
            flag = 0;
            lastSwap = curSwap;
        }
        printf("%d\n", count);
    }
    return 0;
}
