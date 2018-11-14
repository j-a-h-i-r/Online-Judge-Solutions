#include<stdio.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);
    while(t--){
        long long a, b;
        scanf("%lld%lld", &a, &b);

        long long num = b-a+1;

        long long totDiv = (num) - ((num)/3);

        long long rem = num%3, remA = a%3;

        if(rem == 1){
            if(remA == 1) totDiv -= 1;
        }
        else if (rem == 2){
            if(remA == 0 || remA == 1) totDiv -= 1;
        }

        printf("Case %d: %lld\n", ++c, totDiv);
    }
    return 0;
}
