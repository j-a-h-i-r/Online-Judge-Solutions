#include<stdio.h>
#include<math.h>

int main()
{
    double pi = acos(-1);
    int t;
    scanf("%d", &t);
    while(t--) {
        double l;
        scanf("%lf", &l);

        double red = pi*(l*l/25);
        double whole = (l*l*3)/5;

        printf("%.2lf %.2lf\n", red, whole-red);
    }
    return 0;
}
