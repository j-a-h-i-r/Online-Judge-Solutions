#include<stdio.h>
int main()
{
    int i,j,count=2,limit,searchDivisor=2,t,caseno=0,n;

    int sortedByDivisor[1001];
    sortedByDivisor[1]=1;

    int divisorCount[1001]; // keep number of divisor, index is the cortresponding number
    divisorCount[1]=1;      // 1 has only 1 divisor

    for(i=2; i<=1000; i++) {
        limit = i/2;
        for(j=2; j<=limit; j++) {
            if(i%j==0) count++;
        }
        divisorCount[i]=count;
        count=2;
    }

    j=2;
    while(j<=1000) {
        for(i=1000; i>1; i--) {
            if(divisorCount[i] == searchDivisor) sortedByDivisor[j++] = i;
        }
        searchDivisor++;
    }

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++caseno, sortedByDivisor[n]);
    }
}
