#include<stdio.h>
#include<math.h>
int main()
{
    int h, m;
    char c;
    while(scanf("%d%c%d", &h, &c, &m) && (h!=0 || m!=0)) {

        double deg = fabs(h*30.0 - m*5.5);

        if (deg< 360.0 - deg) printf("%.3lf\n", deg);
        else printf("%.3lf\n", 360.0 - deg);

    }
    return 0;
}
