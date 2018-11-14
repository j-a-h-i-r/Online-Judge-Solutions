#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int f;
        long long sum = 0;
        scanf("%d", &f);
        while(f--){
            long long int s, a, d;
            scanf("%lld%lld%lld", &s, &a, &d);
            sum += s*d;
        }

        printf("%lld\n", sum);
    }
    return 0;
}
