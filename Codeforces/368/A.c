#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d", &n,&m);
    getchar();
    int i,j, cl=0;
    for(i=1; i<=n; i++)
    {
        char s[110];
        fgets(s, 120, stdin);
        for(j=0; s[j]!='\n' && s[j]!='\0'; j+=2)
        {
            if(s[j]=='C' || s[j]=='M' || s[j]=='Y') cl = 1;
        }
    }
    if(cl) printf("#Color\n");
    else printf("#Black&White\n");

}
