#include<stdio.h>

int main()
{
    char s[100000], t[100000];
    while(scanf("%s", s) != EOF) {
        getchar();
        scanf("%s", t);
        getchar();

        int i = 0, j;

        for(j=0; t[j]!='\0'; j++) {
            if(s[i]==t[j]) i++;
        }
        if(s[i] == '\0') printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
