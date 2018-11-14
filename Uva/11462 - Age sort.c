#include<stdio.h>
int main()
{
   /* freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout); */
    int n;

    while(scanf("%d", &n) && n != 0) {
        int age[104], i;

        for(i=1; i<101; i++) {
            age[i] = 0;
        }

        while(n--) {
            int a;
            scanf("%d", &a);
            age[a]++;
        }

        for(i=1; i<101; i++) {
            if(age[i] ) {
                printf("%d", i);
                age[i]--;
                break;
            }
        }

        for(i; i<101; i++) {
            while(age[i]--) printf(" %d", i);
        }
        printf("\n");
    }

    return 0;
}
