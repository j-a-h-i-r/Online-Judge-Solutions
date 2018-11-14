#include<stdio.h>
#include<string.h>
#include<limits.h>
int main()
{
    unsigned long long int b1[3], b2[3], b3[3], i,j,sum, min, clr;
    char com[][4]={"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    char bin[4];
    int reColor[26];
    reColor['B'-'0'] = 0;
    reColor['C'-'0'] = 2;
    reColor['G'-'0'] = 1;

    while(scanf("%llu%llu%llu%llu%llu%llu%llu%llu%llu",&b1[0],&b1[1], &b1[2], &b2[0], &b2[1], &b2[2], &b3[0], &b3[1], &b3[2])!=EOF){

        min = 1844674407370955161;

        for(i=0; i<6 ; i++) {
            sum = 0;

            for(j=0; j<3; j++) {
                clr = reColor[com[i][j]-'0'];

                sum += b1[clr]+b2[clr]+b3[clr];

                if(j==0) sum -= b1[clr];
                else if(j==1) sum -= b2[clr];
                else if(j==2) sum -= b3[clr];
            }
            if (sum < min) {
                min = sum;
                strcpy(bin, com[i]);
            }
        }
        printf("%s %d\n",bin, min);
    }
    return 0;
}

