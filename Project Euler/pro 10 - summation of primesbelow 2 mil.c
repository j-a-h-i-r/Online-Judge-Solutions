#include <stdio.h>
#include <math.h>

#define size 2000000
static char ara[size];

void sieve()
{
    unsigned long long int i, j, root;

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

char is_prime(unsigned long long int n){
    if(n<2) {
        return 0;
    }

    return ara[n];
}

int main()
{
    unsigned long long int number;

    printf("Enter number  ");
    scanf("%d", &number);

        unsigned long long int n;
        int nOfPrime,i;

        unsigned long long int prime[number/2];
        sieve();
        for(n=2, i=0; n<=number; n++) {
            if (1 == is_prime(n)) {
                prime[i]=n;
                i++;
            }
            nOfPrime=i;
        }
        for(i=0; i<nOfPrime ; i++) {
            printf("%lu ", prime[i]);
        }
        printf("\nTotal: %d\n", nOfPrime);

}


