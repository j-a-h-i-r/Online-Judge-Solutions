#include<stdio.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);
    while(t--){
        long long n;
        int p = 0;
        scanf("%lld", &n);

        while(n) {
            p += n&1;
            n = n>>1;
        }

        if(p&1 == 1) printf("Case %d: odd\n", ++c);
        else printf("Case %d: even\n", ++c);
    }
    return 0;
}
