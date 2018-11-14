#include<stdio.h>
int main()
{
    int a,s,d;

    while(scanf("%d%d%d", &a, &s, &d)) {
        if (a==0 && s==0 && d ==0) break;

        int max;

        if(a>s && a>d) max = a;
        else if(s>a && s>d) max = s;
        else max = d;

        if( a*a+s*s+d*d-max*max == max*max) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}

