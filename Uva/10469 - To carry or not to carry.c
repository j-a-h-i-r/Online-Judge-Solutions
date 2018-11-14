#include<stdio.h>
#include<math.h>
int main()
{

    unsigned long int m, n;
    while(scanf("%lu%lu", &m, &n) != EOF) {
        unsigned long sum = 0, k = 0, p = 1;

        while(m || n) {
            unsigned long int i = m&1, j = n&1;
            if(i==1 && j==1) p = p*2;
            else {
                sum += (i+j)*p;
                p = p*2;
            }

            m = m>>1;
            n = n>>1;
        }
        printf("%lu\n", sum);
    }
    return 0;
}
