#include<stdio.h>
#include<string.h>

int upper(char a){
    if (a>='A'&& a<='Z') return 1;
    return 0;
}

int main()
{
    char a[120], b[120];

    scanf("%s",a);
    scanf("%s",b);

    int i = 0;

    for(i=0; a[i]; i++){
        if( upper(a[i]) ) a[i] = a[i] + 32;
        if (upper(b[i]) ) b[i] = b[i] + 32;

        if(a[i]<b[i]) {
            printf("-1");
            return 0;
        }
        else if (a[i]>b[i]) {
            printf("1");
            return 0;
        }
    }
    printf("0");
    return 0;
}
