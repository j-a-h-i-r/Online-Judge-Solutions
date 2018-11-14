#include<stdio.h>
int main()
{
    int t, k = 0;
    scanf("%d", &t);

    while(t--) {

        int n;
        scanf("%d", &n);

        n = ((n*63+7492)*5) - 498;

        if(n<0) n = -n;

        n = n/10;

        printf("%d\n", n%10);
    }
    return 0;
}
