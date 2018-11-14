#include<stdio.h>
int main()
{
    int n,d, mx=0, tmx = 0, i, f;
    scanf("%d%d", &n,&d);
    getchar();

    while(d--) {
        f = 1;
        char s[120];

        fgets(s, 110, stdin);

        for(i=0; s[i]!='\n' && s[i]!='\0'; i++) {
            if (s[i] == '0') {
                f = 0;
                break;
            }
        }

        if( f == 0) {
            tmx++;
        }
        else {
            if(tmx>mx) mx = tmx;
            tmx = 0;
        }
    }
    if(tmx>mx) mx = tmx;

    printf("%d\n", mx);
}
