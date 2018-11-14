#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int abundantSum(int a);

const int LIMIT = 28123 ;

const int totAb = 6965;

int main()
{
    int i,j,temp, m=0;
    long int sum=0;

    int * ab;

    ab = (int*) malloc(sizeof(int) * totAb );       // allocate memory to hold all abundant number

    bool *num;

    num = (bool *)calloc(LIMIT+1, sizeof(bool));        // alocate memory to flag a number as ab or non-ab

    for(i=1; i<=LIMIT; i++) {
        if(abundantSum(i)) ab[m++] = i;     // put ab nums into array
    }

    for(i=0; i<totAb; i++) {
        for(j=0; j<totAb; j++) {

            temp = ab[i] + ab[j];

            if(temp<=LIMIT) {
                num[temp]=1;
            }
        }
    }

    for(i=1; i<=LIMIT; i++) {

        if(num[i]==0) sum+=i;
    }

    printf("%ld", sum);
}

int abundantSum(int n) {        // abundant num checker
    int b, sum=1;

    for(b=2; b*b<n; b++) {
        if(n%b==0) {
            sum += b + (n/b);
        }
    }

    if(b*b==n) sum += b;

    return (sum>n);
}
