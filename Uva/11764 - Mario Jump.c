#include<stdio.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);

    while(t--) {
        int h = 0, l = 0, n, pre, cur;
        scanf("%d", &n);

        scanf("%d", &pre);

        while(--n) {
            scanf("%d", &cur);

            if(cur>pre) h++;
            else if(cur<pre) l++;

            pre = cur;
        }

        printf("Case %d: %d %d\n",++c, h, l);
    }
    return 0;
}
