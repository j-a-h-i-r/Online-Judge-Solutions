#include<stdio.h>
int main()
{
    int t;
    long long sum = 0;
    scanf("%d", &t);

    while(t--) {
        char a[10];
        long long int n;

        scanf("%s", a);

        if(a[0]== 'r' ) printf("%lld\n", sum);
        else {
            scanf("%lld", &n);
            sum = sum + n;
        }
    }
    return 0;
}
