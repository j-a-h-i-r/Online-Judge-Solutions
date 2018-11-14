#include<cstdio>
int main()
{
    long n;

    long long fac[16], i;
    fac[8] = 40320;

    for(i = 9; i<=13; i++ ) {
        fac[i] = (fac[i-1]) * i;
    }

    while(scanf("%ld", &n) == 1) {
        if(n<0) {
            if(n%2==0) printf("Underflow!\n");
            else printf("Overflow!\n");
        }

        else {
            if(n<8) printf("Underflow!\n");
            else if(n>13) printf("Overflow!\n");
            else printf("%lld\n", fac[n]);
        }
    }
    return 0;
}
