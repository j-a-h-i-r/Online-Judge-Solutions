#include<stdio.h>
int main()
{
  /* freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout); */

    int t;
    scanf("%d", &t);
    while(t--) {
        long long int l[4], max = -1;
        int invalid = 0, i;

        for(i=0; i<4; i++) {
            scanf("%lld", &l[i]);
            if(l[i]>max) max = l[i];
        }

        if(invalid == 1) {
            printf("banana\n");
        }
        else if( l[0]+l[1]+l[2]+l[3]-max < max ) {
            printf("banana\n");
        }
        else {
            long long a = l[0], b = -1;
            int sq = 1, rec = 1;

            for(i=1; i<4; i++) {
                if(l[i]!=a) {
                    sq=0;

                    if(b==-1) b = l[i];
                    else if(b!=l[i]) rec = 0;
                }
            }

            if(sq==1) {
                printf("square\n");
            }
            else if(rec==1) {
                printf("rectangle\n");
            }
            else {
                printf("quadrangle\n");
            }
        }

    }
    return 0;
}
