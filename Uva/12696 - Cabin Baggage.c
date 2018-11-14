#include<stdio.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);
    while(t--) {
        double l, wd, d, wg;
        scanf("%lf%lf%lf%lf", &l, &wd, &d, &wg);

        if( ((l<=56.0 && wd<=45.0 && d<=25.0 ) || (l+wd+d)<=125.0 ) && wg <=7.00 ) {
            printf("1\n");
            c++;
        }
        else printf("0\n");
    }
    printf("%d\n", c);

    return 0;
}
