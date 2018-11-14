#include<stdio.h>
#include<math.h>
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    int n, c = 0;
    while(scanf("%d", &n)!=EOF) {
        if(n<0) break;

        int s = log10(n)/log10(2);

        if(pow(2, s) == n ) printf("Case %d: %d\n",++c, s);
        else printf("Case %d: %d\n",++c, s+1);
    }
    return 0;
}
