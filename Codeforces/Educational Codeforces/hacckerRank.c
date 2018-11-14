#include<stdio.h>
int main()
{
    char str[20];

    scanf("%s", str);

    int h,m,s;
    char c;

    sscanf(str,"%d:%d:%d%c", &h,&m,&s,&c);

    if(c=='A')
    {
        if(h==12) printf("00:%02d:%02d\n", m,s);
        else printf("%02d:%02d:%02d\n", h,m,s);
    }
    else {
        if(h==12) printf("%02d:%02d:%02d\n", h,m,s);
        else {
            h = h+12;
            printf("%02d:%02d:%02d\n", h,m,s);
        }
    }
    return 0;
}
