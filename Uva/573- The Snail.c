#include<stdio.h>
int main()
{
   /* freopen("in.txt", "r", stdin);*/

    double h,u,d,f;

    while( scanf("%lf%lf%lf%lf",&h,&u,&d,&f) != EOF )
    {
        if( (int)h == 0 ) break;

        int n;
        double cur = 0;
        f = (f/100)*u;

        for( n=1; ; n++ )
        {
            if ( u - (n-1)*f >= 0) cur += ( u - (n-1)*f );

            /*printf("cur %lf ", cur);*/

            if(cur >h) {
                printf("success on day %d\n", n);
                break;
            }

            cur -= d;
            /*printf("Cur slip %lf\n", cur);*/

            if( cur <0 ) {
                printf("failure on day %d\n", n);
                break;
            }
        }
    }

    return 0;
}
