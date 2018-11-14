#include<stdio.h>
#include<string.h>

int palindrome (char s[]) {
    int i;
    int j = strlen(s)-1;

    for (i=0; i<j; i++, j--) {
        if (s[i]!=s[j]) return 0;
    }
    return 1;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int t, c=0;
    char num[20];

    scanf("%d", &t);

    while(t--) {
        scanf("%s", num);

        printf("%s\n", num);

        if (palindrome(num)) printf("Case %d: Yes\n", ++c);
        else printf("Case %d: No\n", ++c);
    }
}
