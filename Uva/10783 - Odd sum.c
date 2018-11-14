#include<stdio.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);
    while(t--){
        int a,b;
        scanf("%d%d", &a, &b);

        if(a%2==0) a = a+1;
        if(b%2==0) b = b-1;

        if(a>b){
            printf("Case %d: 0\n", ++c);
            continue;
        }

        int n = (b-a)/2 + 1;

        int sum = n*(a+n-1);

        printf("Case %d: %d\n", ++c, sum);
    }
}
