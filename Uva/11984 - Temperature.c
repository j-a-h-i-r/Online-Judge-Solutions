#include<stdio.h>
int main()
{
    int t, c=0;
    scanf("%d", &t);
    while(t--) {
        double cel, d;
        scanf("%lf%lf", &cel, &d);

        cel = cel + (d/1.8);

        printf("Case %d: %.2lf\n", ++c, cel);
    }
    return 0;
}
