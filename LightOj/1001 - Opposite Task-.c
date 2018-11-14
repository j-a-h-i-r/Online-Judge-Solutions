#include<stdio.h>
#include <time.h>
#include<stdlib.h>
int main()
{
    srand(time(NULL));

    int test, number, a,b,extra,temp,divisor;
    scanf("%d", &test);

    while(test--) {
        scanf("%d", &number);

        if(number <= 10) {
            a = rand()%(number+1);
            b = (number-a);

            printf("%d %d\n", a,b);
        }
        else {
            divisor = (20 - number + 1);
            extra = number - 10;

            a = (rand()%divisor) + extra;
            b = number - a;

            printf("%d %d\n", a,b);
        }
    }
    return 0;
}
