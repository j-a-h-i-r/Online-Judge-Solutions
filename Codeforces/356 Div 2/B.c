#include<stdio.h>
int main()
{
    int n, a, i;
    scanf("%d%d", &n, &a);

    int city[n+1];

    memset(city, 0, sizeof city);

    for(i=1; i<=n; i++) {
        scanf("%d", &city[i]);
    }

    int cr = city[a];

    for(i=1; i<=n; i++) {
        int x = a+i;
        int y = a-i;

        if(x>=1 && x<=n) {
            if(y>=1 && y<=n) {
                if(city[x] && city[y]) cr = cr+2;
            }
            else if(city[x]) cr++;
        }
        else if (y>=1 && y<=n) {
            if(city[y]) cr++;
        }
    }

    printf("%d\n", cr);

    return 0;
}
