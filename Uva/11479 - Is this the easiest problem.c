#include<stdio.h>
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, cs = 0;
    scanf("%d", &t);

    while(t--) {
        long int a, b, c, max;
        scanf("%ld%ld%ld", &a, &b, &c);

        if(a>b && a>c) max = a;
        else if(b>c && b>a) max = b;
        else max = c;

        if(a<=0 || b<=0 || c<=0) {
            printf("Case %d: Invalid\n", ++cs);
        }
        else if(a+b+c-max<=max) {
            printf("Case %d: Invalid\n", ++cs);
        }

        else {
            if(a==b && b==c && a==c) printf("Case %d: Equilateral\n", ++cs);
            else if(a==b || b==c || a==c) printf("Case %d: Isosceles\n", ++cs);
            else printf("Case %d: Scalene\n", ++cs);
        }
    }

    return 0;
}
