#include<stdio.h>
int main()
{
    int n, h, wd = 0, x;
    scanf("%d%d", &n, &h);

    while(n--) {
        scanf("%d", &x);

        if(x<=h) wd++;
        else wd += 2;
    }

    printf("%d\n", wd);
    return 0;
}
