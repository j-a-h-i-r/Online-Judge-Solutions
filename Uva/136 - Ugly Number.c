#include<stdio.h>
int main()
{
    long long i;
    int c = 0;

    for(i=1; ; i++){
        long long n = i;

        while(n%2==0) n/=2;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;

        if(n==1) {
            c++;
            printf("%d  %lld\n", c, i);
        }

        if(c==1500) break;
    }

}
