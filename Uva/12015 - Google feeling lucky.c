#include<stdio.h>
#include<string.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);

    while(t--) {
        int ri[101], i;
        for(i=0; i<101; i++) {
            ri[i] = 0;
        }

        int max = -1;

        char a[101][11][101];
        int ten = 10;

        while(ten--) {
            char u[101];
            int r;
            scanf("%s%d", u, &r);

            if(r>max) max = r;

            strcpy(a[r][ ri[r]++ ], u);
        }

        printf("Case #%d:\n", ++c);

        for(i = 0; i < ri[max]; i++) {
            printf("%s\n", a[max][i]);
        }
    }
    return 0;
}
