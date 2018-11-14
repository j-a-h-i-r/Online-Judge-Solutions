#include<stdio.h>

int divSum(int n) {
    int sum = 1, i;
    if(n==1) return 0;

    for(i=2; i*i<n; i++) {
        if(n%i==0) {
            sum = sum + i + (n/i);
        }
    }
    if(i*i==n) sum += i;

    return sum;
}

int main()
{
    int n;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &n) && n!=0) {
        int ds = divSum(n);

        if ( ds == n ) printf("%5d  PERFECT\n", n);
        else if(ds<n) printf("%5d  DEFICIENT\n", n);
        else if(ds>n) printf("%5d  ABUNDANT\n", n);
    }
    printf("END OF OUTPUT\n");

    return 0;
}
