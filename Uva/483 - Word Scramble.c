#include<stdio.h>
int main()
{
    int c, i = 0;
    char s[100];
    while((c=getchar())!=EOF) {
        if(!isspace(c)){
            s[i++] = c;
        }
        else {
            for(i=i-1; i>=0; i--){
                printf("%c", s[i]);
            }
            printf("%c", c);
            i = 0;
        }
    }
    return 0;
}
