#include<stdio.h>
#include<string.h>
int main()
{
char s[15];
int c=0;
while(scanf("%s", s) && s[0]!='#'){
printf("Case %d: ", ++c);
if(!strcmp(s, "HELLO")) printf("ENGLISH\n");
else if(!strcmp(s, "HOLA")) printf("SPANISH\n");
else if(!strcmp(s, "HALLO")) printf("GERMAN\n");
else if(!strcmp(s, "BONJOUR")) printf("FRENCH\n");
else if(!strcmp(s, "CIAO")) printf("ITALIAN\n");
else if(!strcmp(s, "ZDRAVSTVUJTE")) printf("RUSSIAN\n");
else printf("UNKNOWN\n");
}
return 0;
}
