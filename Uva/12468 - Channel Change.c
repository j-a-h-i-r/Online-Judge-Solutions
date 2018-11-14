#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    while(scanf("%d%d", &a, &b) && (a!=-1 || b!=-1)) {
        int dif = abs(a-b);

        if(dif<100-dif) printf("%d\n", dif);
        else printf("%d\n", 100-dif);
    }
    return 0;
}
