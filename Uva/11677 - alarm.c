#include<stdio.h>
int main()
{
    int h1, m1, h2, m2;

    while(scanf("%d%d%d%d", &h1, &m1, &h2, &m2)){
        if(h1==0&&m1==0&&h2==0&&m2==0) break;

        int dh, dm;
        dh = h2 - h1;
        dm = m2 - m1;
        if(dh<0) dh = dh+24;

        int sleep = (dh*60) + (dm);

        if(sleep<0) sleep += 1440;

        printf("%d\n", sleep);
    }
    return 0;
}
