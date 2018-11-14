#include<stdio.h>
int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout); */

    int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

    long int n, m;

    while(scanf("%ld%ld", &n, &m)) {
        if(n==0 && m== 0) break;

        int num[55], denom[55], i,j,k, end;

        if(n-m>m) {
            end = m;
        }
        else {
            end = n-m;
        }

        for(i=0; i<end; i++) {
            num[i] = n-end+1+i;
            denom[i] = i+1;
        }

        /*
        for(i=0; i<end; i++) {
            printf("%d*", num[i]);
        }
        printf("\n");
        for(i=0; i<end; i++) {
            printf("--");
        }
        printf("\n");
        for(i=0; i<end; i++) {
            printf("%d*", denom[i]);
        }
        printf("\n");
        */

        /**
        * i = prime index
        * j = numerator index
        * k = denominator index
        **/
        for(i=0; i<15 && prime[i]<=end; i++){
            k=0; // should start from first denominator
            //printf("Diving by %d:\n", prime[i]);
            for(j = 0; j<end && prime[i]<=num[j]; j++) {

                if(num[j]%prime[i]==0) {
                    //printf("Numerator %d can be divided by %d\n", num[j], prime[i]);

                    for(k; k<end && prime[i]<=denom[k]; k++) {
                        if(denom[k]%prime[i] == 0) {
                           // printf("Denom %d can be divided by %d\n", denom[k], prime[i]);
                            num[j] = num[j]/prime[i];
                            denom[k] = denom[k]/prime[i];
                            //printf("Numerator %d\n", num[j]);
                            //printf("Denominator %d\n", denom[k]);
                            j--;
                            break;
                        }
                    }
                    if(k==end) break;
                    k--;
                }
            }
        }

        long int facto = 1;
        for(i=0; i<end; i++) {
            facto = facto*num[i];
        }
        printf("%d things taken %d at a time is %ld exactly.\n", n, m, facto);
    }
}
