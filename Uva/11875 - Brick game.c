#include<stdio.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        int i;
        for(i = 0; i<n; i++) scanf("%d", &a[i]);

        printf("Case %d: %d\n",++c, a[(n-1)/2]);
    }
    return 0;
}
