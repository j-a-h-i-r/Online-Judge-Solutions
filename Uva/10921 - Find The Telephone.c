#include<stdio.h>

char Tel(char c){
    if(c=='0'||c=='1'||c=='-') return c;
    else if(c>='A' && c<='C') return '2';
    else if(c>='D' && c<='F') return '3';
    else if(c>='G' && c<='I') return '4';
    else if(c>='J' && c<='L') return '5';
    else if(c>='M' && c<='O') return '6';
    else if(c>='P' && c<='S') return '7';
    else if(c>='T' && c<='V') return '8';
    else if(c>='W' && c<='Z') return '9';
}

int main()
{
    char s[40];
    while(fgets(s, 40, stdin)!=NULL){
        int i = 0;
        for(i; s[i]!='\n'; i++){
            printf("%c", Tel(s[i]));
        }
        printf("\n");
    }
    return 0;
}
