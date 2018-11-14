#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        double x,y,r;
        scanf("%lf%lf%lf", &x, &y, &r);
        double l = sqrt((x*x)+(y*y));
        printf("%.2lf %.2lf\n", r-l, r+l);
    }
    return 0;
}
