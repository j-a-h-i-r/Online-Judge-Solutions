#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int letterCount[26];
    char s[100007];
    int t, cs = 0;
    scanf("%d", &t);
    while(t--)
    {
        for(int i=0; i<26; i++) letterCount[i] = 0;
        int mn = 100010;
        scanf("%s", s);
        for(int i=0; s[i]!='\0'; i++)
        {
            letterCount[ s[i]-'a']++;
        }
        for(int i=0; i<26; i++)
        {
            if( mn > letterCount[i] ) mn = letterCount[i];
        }
        printf("Case %d: %d\n", ++cs, mn);
    }
    return 0;
}
