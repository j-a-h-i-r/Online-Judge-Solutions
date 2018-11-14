#include<stdio.h>
int main()
{
    long long int a, b;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &a, &b);
        long long int f1, f2, temp;
        if(a<b) {
            printf("impossible\n");
            continue;
        }
        f1 = a+b; f2 = a-b;
        if(f1&1==1 || f2&1==1) printf("impossible\n");
        else{
            printf("%lld %lld\n", f1/2, f2/2);
        }
    }
    return 0;
}
