#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int x, y, z;
        int a;
        scanf("%d%d%d", &x, &y, &z);

        a = ( z * ( (2*x) - y ) ) / (x+y) ;

        printf("%d\n", a);
    }
    return 0;
}
