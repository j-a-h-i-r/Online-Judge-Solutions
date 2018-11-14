#include<stdio.h>
#include<math.h>
int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b)) {
        if(a==0 && b==0) break;

        int sa = sqrt(a);
        int sb = sqrt(b);

        if(sa*sa == a) printf("%d\n", sb-sa+1);
        else printf("%d\n", sb-sa);
    }
    return 0;
}
