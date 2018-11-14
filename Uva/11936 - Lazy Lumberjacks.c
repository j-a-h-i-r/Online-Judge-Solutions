#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,s,d, max;
        scanf("%d%d%d", &a,&s,&d);

        if(a>s && a>d) max = a;
        else if(s>a && s>d) max = s;
        else max = d;

        if(a+s+d-max>max) printf("OK\n");
        else printf("Wrong!!\n");
    }
    return 0;
}
