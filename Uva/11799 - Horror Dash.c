#include<stdio.h>
int main()
{
    int t, n, max,s, c=0;

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &s);
            if (s>max) max=s;
        }
        printf("Case %d: %d\n", ++c, max);
        max=0;
    }
}
