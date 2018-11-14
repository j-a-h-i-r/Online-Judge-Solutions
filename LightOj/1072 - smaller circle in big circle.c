#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,caseno=0;
    double halfTheta,R,r;
    scanf("%d", &t);

    while(t--) {
        scanf("%lf %d",&R,&n);
        halfTheta = sin(3.14159265359/n);
        r=(R*halfTheta)/(1+halfTheta);
        printf("Case %d: %lf\n",++caseno,r);
    }
}
