#include<stdio.h>
int main()
{
    long long n;
    scanf("%I64d", &n);

    long long a,b,c,d, ans1, ans2;

    if(n%2LL == 0)
    {
        a = n/2 - 1;
        b = 1;
        c = a + b;
        d = c + 1;

        ans1 = a*d;
        ans2 = c*d - a*b;
    }
    else
    {
        a = 1;
        b = (n-1)/2;
        c = b + 1;
        d = n;

        ans1 = b*c*2;
        ans2 = c*d - a*b;
    }

    if(ans1 > 0 && ans2 > 0)
    {
        if(ans1<ans2) printf("%I64d %I64d\n", ans1, ans2);
        else printf("%I64d %I64d\n", ans2, ans1);
    }
    else printf("-1\n");



}
