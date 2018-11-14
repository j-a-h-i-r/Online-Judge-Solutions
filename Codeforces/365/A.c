#include<stdio.h>
int main()
{
    int n,m=0,c=0;
    scanf("%d", &n);

    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        if(a>b) m++;
        else if(b>a) c++;
    }
    if(m>c) printf("Mishka\n");
    else if(c>m) printf("Chris\n");
    else printf("Friendship is magic!^^\n");

    return 0;
}
