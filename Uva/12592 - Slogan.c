#include<stdio.h>
#include<string.h>
int main()
{
   /* freopen("in.txt", "r", stdin);*/

    int n, i;
    scanf("%d", &n);

    getchar();

    char slogan1[n+1][120], slogan2[n+1][120];

    for(i=0; i<n; i++) {
        fgets(slogan1[i], 120, stdin);
        fgets(slogan2[i], 120, stdin);
    }

    int q;
    scanf("%d", &q);
    getchar();

    while(q--) {
        char temp[120];
        fgets(temp, 120, stdin);

        for(i=0; i<n; i++) {
            if ( strcmp(temp, slogan1[i]) == 0 ) {
                printf("%s", slogan2[i]);
                break;
            }
        }
    }

    return 0;
}
