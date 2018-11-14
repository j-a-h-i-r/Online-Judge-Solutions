#include<stdio.h>
#include<math.h>
int main()
{

    int t, c=0;
    scanf("%d", &t);

    while(t--) {
        double in, tax = 0;
        scanf("%lf", &in);

        if(in <= 180000.0) {
            printf("Case %d: 0\n", ++c);
            continue;
        }

        in = in - 180000.0;

        if(in <= 300000.0) {
            tax = in*.10;
            if(tax < 2000.0) printf("Case %d: 2000\n", ++c);
            else printf("Case %d: %.0lf\n",++c, ceil(tax));
            continue;
        }

        tax = 30000.0;
        in = in - 300000.0;

        if(in <= 400000.0) {
            tax = tax + (in*.15);
            printf("Case %d: %.0lf\n",++c, ceil(tax) );
            continue;
        }

        tax = 90000.0;
        in = in - 400000.0;

        if(in <= 300000.0) {
            tax = tax + (in*.20);
            printf("Case %d: %.0lf\n",++c, ceil(tax) );
            continue;
        }

        tax = 150000;

        in = in - 300000.0;
        tax = tax + (in*.25);

        printf("Case %d: %.0lf\n",++c, ceil(tax) );
    }
    return 0;
}
