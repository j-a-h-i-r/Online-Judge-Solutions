#include<stdio.h>
#include<string.h>

int main()
{
    int i;
    char n[1020];

    while(scanf("%s", n)!=EOF) {
        if(n[0]=='0' && n[1]=='\0') break;
        int l = strlen(n), odd = 0, even = 0;
        for(i=0; i<l; i+=2 ) odd += (n[i]-'0');
        for(i=1; i<l; i+=2 ) even += (n[i]- '0');

        if (odd == even) printf("%s is a multiple of 11.\n", n);
        else if(odd>even) {
            if ((odd-even)%11 == 0) printf("%s is a multiple of 11.\n", n);
            else printf("%s is not a multiple of 11.\n", n);
        }
        else {
            if ((even - odd)%11 == 0) printf("%s is a multiple of 11.\n", n);
            else printf("%s is not a multiple of 11.\n", n);
        }
    }
    return 0;
}
