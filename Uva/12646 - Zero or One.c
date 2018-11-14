#include<stdio.h>
int main()
{
    int n[4];
    while(scanf("%d%d%d", &n[0], &n[1], &n[2]) != EOF) {
        int i = 0, el = 1, notE = -1;

        for(i=1; i<3; i++) {
            if(n[i]==n[0]) el++;
            else notE = i;
        }

        if(el == 3) printf("*\n");
        else if(el == 1) printf("A\n");
        else printf("%c\n", 'A' + notE);
    }
    return 0;
}
