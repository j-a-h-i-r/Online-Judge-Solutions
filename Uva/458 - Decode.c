#include<stdio.h>
int main()
{
    char c;

    while(scanf("%c", &c)!=EOF ) {
        if(c=='\n' || c=='\0') printf("%c", c);
        else printf("%c", c-7);
    }
    return 0;
}
