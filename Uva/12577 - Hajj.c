#include<stdio.h>
#include<string.h>
int main()
{
    char c[10], h[] = "Hajj", u[] = "Umrah";
    int cs = 0;
    scanf("%s", c);

    while(c[0]!='*' && c[1]!='\n') {

        if(!strcmp(c, h)) printf("Case %d: Hajj-e-Akbar\n", ++cs);
        else if(!strcmp(c, u)) printf("Case %d: Hajj-e-Asghar\n", ++cs);

        scanf("%s", c);
    }
    return 0;
}
