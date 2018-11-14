#include<stdio.h>

int main()
{
    long long int w, odd, even;
    int t, i, caseno=0, flag=0;

    scanf("%d", &t);

    while(t--){
        scanf("%lld", &w);

        if (w%2 != 0) {printf("Case %d: Impossible\n", ++caseno); continue; }

        for (i=2; i<w/2 ; ) {

            if (w%i == 0 ) {
                odd = w/i; even=i;

                if (odd%2 == 0) { i = i*2; }
                else {flag=1;  break; }
            }
        }
        if (flag==1) printf("Case %d: %lld %lld\n",++caseno,odd, even);
        else printf("Case %d: Impossible\n", ++caseno);
        flag=0;
    }
}
