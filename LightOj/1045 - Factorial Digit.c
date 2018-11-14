#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double dig[1000010];
long n,b,in,res;

int main()
{
    int t, caseno=0;

    dig[0] = 0.0;

    for(in=1; in<=1000000;  in++) {
        dig[in] = log(in) + dig[in-1]  ;
    }

    scanf("%d",&t);

    while(t--) {
        scanf("%ld%ld", &n, &b);

        if (b<2) continue;

        res = (long)(dig[n]/log(b)) + 1;

        printf("Case %d: %ld\n", ++caseno, res);
    }
}
