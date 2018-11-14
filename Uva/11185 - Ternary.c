#include<stdio.h>
int main()
{
    long long n;

    while(scanf("%lld", &n) && n>=0) {
        int t[100];
        int i = 0;

        if(n==0) {
            printf("0\n");
            continue;
        }
        while(n) {
            t[i++] = n%3;
            n/=3;
        }

        for(i=i-1; i>=0; i--) {
            printf("%d", t[i]);
        }
        printf("\n");
    }
}
