#include<stdio.h>
int main()
{
    int p[] = {2,3,5,7} , c = 0, i;
    int p2[] = {11,13,17,19,23,29,31,37,41,43,47};
    char s[5];

    for(i=0; i<4; i++) {
        printf("%d\n", p[i]);

        fflush(stdout);

        scanf("%s", s);

        if(s[0] == 'y') {
            c++;

            printf("%d\n", p[i]*p[i]);
            fflush(stdout);

            scanf("%s", s);

            if(s[0] == 'y') {
                c++;
                break;
            }
        }
    }

    if(c>=2) {
        printf("composite\n");
        fflush(stdout);
    }
    else {
        for(i=0;i<11; i++) {
            printf("%d\n", p2[i]);
            fflush(stdout);

            scanf("%s",s);

            if(s[0] == 'y') c++;

            if(c>=2) break;
        }

        if(c>=2) printf("composite\n");
        else printf("prime\n");

        fflush(stdout);
    }

    return 0;
}
