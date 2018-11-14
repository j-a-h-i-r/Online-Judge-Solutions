#include <iostream>
#include <math.h>
using namespace std;

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
    unsigned long long int number, sum=0;

    cout<<"Enter number  ";
    cin>>number;

        unsigned long long int n;
        int nOfPrime,i;

        static unsigned long long int prime[20000];
        sieve();
        for(n=2, i=0; n<=number; n++) {
            if (1 == is_prime(n)) {
                sum=sum+n;
                i++;
                cout<<".";
            }
            nOfPrime=i;
        }
        cout<<sum;
}


