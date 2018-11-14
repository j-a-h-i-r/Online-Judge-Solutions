#include<stdio.h>

int main()
{
    int i;
    unsigned long long int prod=100;

    for(i=99; i>1; i--) {

        prod *= i;

        printf("%d %llu\n", i, prod);

        while(prod%10==0) {

            prod/=10;

            //printf("%llu\n", prod);
        }
    }

    printf("%llu", prod);
}
