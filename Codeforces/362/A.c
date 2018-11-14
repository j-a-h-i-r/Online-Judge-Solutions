#include<stdio.h>
int main()

{
    long long int t,s,x;
    scanf("%I64d%I64d%I64d", &t, &s, &x);

    if ( x == t+1 || x<t) printf("NO\n");

    else {
    if ( (x-t)%s == 0 || (x-t-1)%s == 0 )
    {
        printf("YES\n");
    }
    else printf("NO\n");
    }

    return 0;
}
