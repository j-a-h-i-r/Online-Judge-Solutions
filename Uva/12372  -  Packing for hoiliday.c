#include<stdio.h>
int main()
{
    int t, c=0;
    scanf("%d", &t);

    while(t--) {
        int l, h, w;
        scanf("%d%d%d", &l, &h, &w);
        if(l>20 || h>20 || w>20) printf("Case %d: bad\n", ++c);
        else printf("Case %d: good\n", ++c);
    }
    return 0;
}
