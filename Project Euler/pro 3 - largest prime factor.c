#include <stdio.h>
#include <math.h>

#define size 775146
char ara[size];

void sieve()
{
    int i, j, root;

    for(i=2; i<size; i++) {
        ara[i]=1;
    }

    root=sqrt(size);
    for(i=2; i<root; i++){
        if(ara[i]==1) {
            for(j=2; i*j<size; j++) {
                ara[i*j]=0;
            }
        }
    }
}

char is_prime(int n){
    if(n<2) {
        return 0;
    }

    return ara[n];
}

int main()
{
        int n,i,number=775146, nOfPrime;
        int prime[number/2];
        sieve();
        for(n=2, i=0; n<=number; n++) {
            if (1 == is_prime(n)) {
                prime[i]=n;
                i++;
            }
            nOfPrime=i;
        }
        for(i=nOfPrime-1; i>=0 ; i--) {

            if((600851475143%prime[i])==0) {
                printf("\n%d", prime[i]);
                break;
            }
        }
}

