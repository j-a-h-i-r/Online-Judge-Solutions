#include<stdio.h>
int main()
{
    int t, cs=0;
    scanf("%d", &t);
    while(t--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if((a>b && a<c) || (a<b&&a>c)) printf("Case %d: %d\n", ++cs, a);
        else if((b>c&&b<a)||(b>a&&b<c)) printf("Case %d: %d\n", ++cs, b);
        else printf("Case %d: %d\n", ++cs, c);
    }
    return 0;
}
