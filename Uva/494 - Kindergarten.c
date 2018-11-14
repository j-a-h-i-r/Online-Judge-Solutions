#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char c;
    int count = 0, cont = 0;

    while(scanf("%c", &c)!=EOF) {
        if(c=='\n') {
            printf("%d\n", count);
            count = 0;
            cont = 0;
            continue;
        }

        if ( (isspace(c)||ispunct(c)||isdigit(c)) && cont == 1) {
            cont = 0;
        }

        if (isalpha(c) && cont == 0 ) {
            cont = 1;
            count++;
        }
    }
    return 0;
}
