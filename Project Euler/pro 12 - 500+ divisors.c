#include<stdio.h>

int totalDivisor(int a);

int main()
{
    int i, a;

    for(i=31; ; i++) {

        if( (a=totalDivisor(((i*(i+1))/2))) >= 500) {
            break;
        }
    }
    printf("%d", (i*(i+1)/2));
}

int totalDivisor(int n) {        // divisor counter
    int b, count=2;

    for(b=2; b*b<n; b++) {
        if(n%b == 0) {
            count += 2;
        }
    }

    if(b*b == n) count++;

    return count;
}
