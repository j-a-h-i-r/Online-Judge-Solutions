#include<stdio.h>
#include<math.h>
double sq(double x)
{
    return x*x;
}

int main()
{
    double sx, sy, ans = 500 ;
    int n, i;
    scanf("%lf%lf",&sx,&sy);
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        double x,y,v;
        scanf("%lf%lf%lf",&x,&y,&v);

        double dis = sqrt(sq(x-sx)+sq(y-sy));

        if( dis/v < ans ) ans = dis/v;
    }
    printf("%lf\n", ans);
}
