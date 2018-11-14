#include<stdio.h>
int main()
{
    int n, k;

    while(scanf("%d%d", &n, &k)!=EOF) {
        int m = n, sum = 0;

        while(m>=k) {
            sum = sum + (m/k);
            m = (m/k) + (m%k);
        }
        printf("%d\n", n + sum);
    }
    return 0;
}
