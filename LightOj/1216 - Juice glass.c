#include<stdio.h>

const double pi3 = 1.047197551196;

int main()
{
    int t, c=0;
    scanf("%d", &t);
    while(t--){
        double r1, r2, h, p;
        scanf("%lf%lf%lf%lf", &r1, &r2, &h, &p);

        double d = ((h-p)*(r1-r2))/h;
        double ans = pi3 * (((r1-d)*(r1-d)*(r1-d)) - r2*r2*r2);
        printf("Case %d: %.9lf\n", ++c, ans);
    }
}
