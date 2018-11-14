#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);

    getchar();

    while(t--) {
        char a[10010];
        fgets(a, 10010, stdin);

        int l = strlen(a) - 1, i, j;
        int rl = sqrt(l);

        if( (rl*rl) != l ) {
            printf("INVALID\n");
        }
        else {
            for(i = 0; i<rl; i++) {
                for(j = i;  j<l; j+=rl) {
                    printf("%c", a[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
