#include<stdio.h>
int main()
{
    //freopen("in.txt", "r", stdin);

    int n, dis = 0;
    long long x;
    scanf("%d %I64d", &n,&x);
    getchar();

    while(n--) {
        char c;
        long long d;
        scanf("%c %I64d", &c, &d);
        getchar();

        if( c == '+') x += d;
        else {
            if( d > x) dis++;
            else x -= d;
        }
    }
    printf("%I64d %d\n", x, dis);
}
