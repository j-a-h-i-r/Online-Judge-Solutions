#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m, sum = 0;

        scanf("%d%d", &n, &m);

        while(n>=m) {
            sum += n/m;

            n = (n/m) + (n%m);
        }

        if(n==1) printf("%d\n", sum);
        else printf("cannot do this\n");
    }
    return 0;
}
