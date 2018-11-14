#include<stdio.h>
#include<string.h>
int main()
{
    char s[150];
    fgets(s,148, stdin);

    int a, b = 0;

    sscanf(s, "%d", &a);

    int i = 0, dec = 0, j=0;
    for(i=0; s[i]!='.'; i++) { }
    for(i=i+1; s[i]!='e'; i++) {
        dec++;
    }
    for(i=i+1; s[i]!='\n'; i++) {
        b = b*10 + (s[i]-'0');
    }
    for(i=0; s[i]!='.'; i++) { }
    i++;

    //printf("%d %d\n", dec, b);

    printf("%d", a);

    if(dec>b) {
        while(b--) printf("%c", s[i++]);

        printf(".");

        while(s[i]!='e') printf("%c", s[i++]);
    }
    else {
        for(j=0; j<dec; j++) printf("%c", s[i++]);
        while( dec < b )
        {
            printf("0");
            dec++;
        }
    }
    return 0;
}
