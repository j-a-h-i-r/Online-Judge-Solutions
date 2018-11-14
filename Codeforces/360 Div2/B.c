#include<stdio.h>
int main()
{
    char s[100909];
    fgets(s, 100900, stdin);

    int i = 0;

    while( s[i] != '\0' && s[i]!='\n') {
        printf("%c", s[i]);
        i++;
    }
    i--;
    while(i>=0) {
        printf("%c", s[i]);
        i--;
    }

    printf("\n");

    return 0;
}
