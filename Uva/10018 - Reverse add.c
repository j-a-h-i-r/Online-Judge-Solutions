#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        char n[15];
        int count = 0;
        scanf("%s", n);
        int i = 0; j = strlen(n) - 1;

        while(!palindrome(n)) {
            for(; i<=j; i++, j--){
                n[i] = n[i]
            }
        }
        printf("%d %s\n", count, n);
    }
}
