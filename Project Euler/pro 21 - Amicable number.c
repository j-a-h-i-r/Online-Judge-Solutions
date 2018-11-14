#include<stdio.h>

int sumOfNum (int a);

int main()
{
    int i, sum, ssum, finalSum=0;

    for(i=1; i<=10000; i++) {

        sum = sumOfNum(i);

        if(i<=sum || sum>10000) continue;

        ssum = sumOfNum(sum);

        if(ssum == i) finalSum = finalSum + i + sum;
    }

    printf("%d", finalSum);
}

int sumOfNum(int n) {
    int a, sum=0;

    for(a=1; a<=n/2; a++) {
        if(n%a==0) sum += a;
    }

    return sum;
}


