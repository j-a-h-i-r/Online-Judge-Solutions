#include<stdio.h>

int half(int n) {
    if(n==1) return 0;
    else if (n==2) return 1;

    if(n%2 == 0) return (1+half(n/2));
    else return (1+half((n+1)/2));
}

int main()
{
    int n, c=0;

    while(scanf("%d", &n)!= EOF) {
        if(n<0) break;

        printf("Case %d: %d\n",++c, half(n));
    }
    return 0;
}
