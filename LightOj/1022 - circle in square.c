#include<stdio.h>
#include<math.h>

int main()
{
    int t, caseno=0;
    double r, cirArea, sqArea, shade;
    double pi = 2 * acos (0);

    scanf("%d", &t);

    while(t--) {
        scanf("%lf", &r);

        sqArea = r*r*4;
        cirArea = pi*r*r;
        shade = sqArea - cirArea;

        printf("Case %d: %.2lf\n", ++caseno, shade);
    }
}
