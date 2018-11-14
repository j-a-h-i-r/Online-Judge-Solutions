#include<stdio.h>
int main()
{
    int n;
    while( (scanf("%d", &n) != EOF)  && n!=0 ) {
        int i, sum =0;
        for(i = 1; i<=n; i++) {
            sum += (i*i);
        }
        printf("%d\n", sum);
    }
    return 0;
}
