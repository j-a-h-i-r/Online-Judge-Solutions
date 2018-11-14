#include<stdio.h>
int main()
{
    long long n;

    while(scanf("%lld", &n) && n!=0 ) {
        int sum = 0;

        while(1){

            while(n) {
                sum += (n%10);
                n /= 10;
            }
            if(sum<10) {
                printf("%d\n", sum);
                break;
            }
            else {
                n = sum;
                sum = 0;
            }
        }
    }
    return 0;
}
