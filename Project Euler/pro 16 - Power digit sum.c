#include<stdio.h>
int main()
{
    int i, k=1, j, c = 0, z;
    int num[1000];
    num[0]=2;

    for(i=1; i<1000; i++) {
        for(j=0; j<k; j++) {

            int m = num[j]*2 + c;

            num[j] = m%10;

            c = m/10;
        }
        if(c!=0) {
            num[k++] = c;
            c = 0;
        }
    }

    printf("%d\n", k);

    int sum = 0;

    for(i=0; i<k; i++) {
        printf("%d ", num[i]);

        sum += num[i];
    }

    printf("\n%d\n",sum);
}
