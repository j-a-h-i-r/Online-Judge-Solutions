#include<stdio.h>
#include<string.h>

int main()
{
    int dur, n, mon, i=0, j=0, months;
    double dp, loan, car, rate, lpm;
    double dep[101];
    memset(dep, -1, sizeof(dep));

    scanf("%d%lf%lf%d", &dur, &dp, &loan, &n);

    while(dur>0) {
        memset(dep, -1, sizeof(dep));
        months = 0;
        car = dp + loan;
        lpm = loan/dur;

        while(n--) {
            scanf("%d%lf", &mon, &rate);
            dep[mon] = rate;
        }
        loan = loan + lpm;
        for(i=0; i<=dur; i++) {
            if ( dep[i]>0 ) j=i;
            car = car*(1.0 - dep[j] );
            loan = loan - lpm;

            if(loan>car) months++;
            else break;
        }

        printf("%d ", months);
        if(months != 1) printf("months\n");
        else printf("month\n");


        scanf("%d%lf%lf%d", &dur, &dp, &loan, &n);
        j=0;
    }

}
