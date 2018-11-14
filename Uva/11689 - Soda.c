#include<stdio.h>
int main()
{
    int t;
    (scanf("%d", &t));

    while(t--) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        int tot = a+b, sum = 0 ;

        while(tot>=c) {
            sum += (tot/c);
            tot = (tot/c) + (tot%c);
        }

        printf("%d\n", sum);
    }
    return 0;
}


