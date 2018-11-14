#include<stdio.h>
int main()
{
    freopen("in.txt", "r", stdin);

    int t, i, j;
    scanf("%d", &t);

    getchar();
    while(t--) {

        int lk[12], nlk[12];
        for(i = 0; i<12; i++) {
            lk[i] = 0;
            nlk[i] = 0;
        }

        int semiTest;
        scanf("%d", &semiTest);
        getchar();

        while(semiTest--) {

            int d, l;
            int s;

            scanf("%d%d", &d, &l);
            getchar();
            s = getchar();

            if(l==0 && s=='i') {
                nlk[d]++;
            }
            else if(l==1 && s=='c' ) {
                lk[d]++;
            }
        }

        int sum = 0;

        for(i=1; i<11; i++){
        }

        for( i = 1; i<10; i++) {
            int tSum = 0;
            if(nlk[i]>0) {
                for( j = i+1; j<11; j++) {
                    tSum += lk[j];
                }
                sum += (nlk[i]*tSum);
            }
        }

        printf("%d\n", sum);

    }
    return 0;
}
