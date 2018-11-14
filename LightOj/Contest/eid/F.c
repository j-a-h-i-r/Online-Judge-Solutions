#include<stdio.h>
int main()
{
    int t, cs = 0;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        char s[30];
        int a,b,c,d;
        fgets(s,28, stdin);
        sscanf(s,"%d.%d.%d.%d",&a,&b,&c,&d);

        //scanf("%d%d%d%d", &a,&b,&c,&d);
        printf("Case %d: %o.%o.%o.%o\n",++cs, a,b,c,d);
    }
    return 0;
}
