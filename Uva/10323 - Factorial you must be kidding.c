#include<stdio.h>
int main()
{
    freopen("in.txt", "r", stdin);

    int t, i, j;
    scanf("%d", &t);
    printf("test = %d\n", t);
    while(t--) {

        int lk[12], nlk[12]; // index will be difficulty
        for(i = 0; i<12; i++) {
            lk[i] = 0;
            nlk[i] = 0;
        }

        int semiTest;
        scanf("%d", &semiTest);

        printf("semi = %d\n", semiTest);

        while(semiTest != 0) {

            int d, l;
            char s;

            scanf("%d%d%c", &d, &l, &s);
            printf("d = %d  l = %d  s = %c\n", d, l, s);

            if(l==0 && s=='i') nlk[d]++;
            else if(l==1 && s=='c' ) lk[d++];

            int sum = 0;

            for( i = 0; i<10; i++) {
                if(nlk[i]>0) {
                    for( j = i+1; j<11; j++) {
                        sum = sum + (nlk[i]*lk[j]);
                    }
                }
            }
            //printf("%d\n", sum);

            --semiTest;
        }

    }
}
