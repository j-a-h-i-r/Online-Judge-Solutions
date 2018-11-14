#include<stdio.h>
#include<string.h>

int palindrome(char a[]){
    int i = 0, j = strlen(a)-1;

    for(i; i<j; i++, j--){
        if(a[i]!=a[j]) return 0;
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        int c = 0;
        long long int n;
        scanf("%lld", &n);
        char s[15];
        snprintf(s, 15, "%lld", n);

        while(!palindrome(s)) {
            c++;

            long long int t = n, re = 0;
            while(t>0) {
                re = (re*10) + t%10;
                t = t/10;
            }
            n = n + re;
            snprintf(s, 15, "%lld", n);
        }
        printf("%d %s\n", c, s);
    }
}
