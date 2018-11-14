#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, cs = 0, i, j;
    scanf("%d", &t);

    while(t--)
    {
        double r[3];
        scanf("%lf%lf%lf", &r[0], &r[1], &r[2]);
        double pr, sum;
        pr = r[0]*r[1]*r[2];
        sum = r[0]+r[1]+r[2];
        double ts = 0;

        for(i=0; i<3; i++)
        {
            double tpr = 2*(pr/r[i]);
            double lob = 1;
            for(j=0; j<3; j++)
            {
                if(i==j) continue;
                lob *= (r[i]+r[j]);
            }
            ts += r[i]*r[i]*acos( 1 - tpr/lob );
        }

        double ans = sqrt(pr*sum) - .5*ts;

        printf("Case %d: %.10lf\n", ++cs, ans);
    }
    return 0;
}

