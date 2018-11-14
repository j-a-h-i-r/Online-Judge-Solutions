#include<stdio.h>
int main()
{
    int d;
    while(scanf("%d", &d)!=EOF) {
        if(d%6 == 0) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
