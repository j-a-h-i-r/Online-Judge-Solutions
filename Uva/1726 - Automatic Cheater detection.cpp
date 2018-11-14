#include<cstdio>
#include<algorithm>
int main()
{
    freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    while(t--) {

        int lk[12], nlk[12]; // index will be difficulty
        for(int i = 0; i<12; i++) {
            lk[i] = 0;
            nlk[i] = 0;
        }

        int semiTest;
        scanf("%d", &semiTest);

        printf("semi = %d\n", semiTest);

        while(semiTest--) {

            int d, l;
            unsigned int s;

            scanf("%d%d%c", &d, &l, &s);
            //printf("d = %d  l = %d  s = %c\n", d, l, s);

            if(l==0 && s=='i') nlk[d]++;
            else if(l==1 && s=='c' ) lk[d++];

            int sum = 0;

            for(int i = 0; i<10; i++) {
                if(nlk[i]>0) {
                    for(int j = i+1; j<11; j++) {
                        sum = sum + (nlk[i]*lk[j]);
                    }
                }
            }
            //printf("%d\n", sum);
        }

    }
}
