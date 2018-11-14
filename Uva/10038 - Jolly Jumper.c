#include<stdio.h>

int main()
{
    long long int n, sum=0, diff, i, a=0, b;

    while(scanf("%lld", &n)!=EOF) {
        sum = 0;
        a = 0;

        if (n==1) {printf("Jolly\n"); scanf("%lld", &a); continue;}
        scanf("%lld", &a);

        for (i=1; i<n; i++) {
            scanf("%lld", &b);
            if(sum == -1) continue;
            diff = b-a;
            if(diff<0) diff=diff*(-1);

            if(diff>=n || diff==0) {sum=-1; continue; }
            sum+=diff;
            a=b;
        }
        if(sum == -1) printf("Not jolly\n");
        else if (sum == ((n-1)*n)/2 ) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
