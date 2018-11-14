#include<stdio.h>
int main()
{
    char c;
    int first=1;

    while(scanf("%c", &c)!=EOF){
        if(c=='"'){
            if(first == 1) {printf("``"); first=0;}
            else {printf("''"); first=1; }
        }
        else printf("%c", c);
    }
    return 0;
}
