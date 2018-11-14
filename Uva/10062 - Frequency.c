#include<stdio.h>
#include<string.h>
#define START 32
int main()
{
    char line[1010];
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int nul=1;
    if(fgets(line, 1010, stdin)==NULL) {nul = 0;}
    while(nul) {
        int i, j, max = 98;

        int freq[100][2];
        for(i=0; i<100; i++) {
            freq[i][1] = 0;
        }

        for(i=0; line[i]!='\n' && line[i]!='\0' && line[i]!='\r'; i++) {
            freq[ line[i]- START ][0] = line[i]- START ;
            freq[ line[i]- START ][1]++;
            /*if(line[i] - START > max) max = line[i] - START; */
        }
        /*
        SORTING DATA
        */
        for(i=0; i<max-1; i++) {
            for(j=i+1; j<max; j++) {
                if(freq[i][1]>=freq[j][1]){
                    int t0, t1;

                    t0 = freq[i][0];  t1 = freq[i][1];
                    freq[i][0]=freq[j][0];   freq[i][1] = freq[j][1];
                    freq[j][0]=t0;    freq[j][1] = t1;
                }
            }
        }  /* SORTED */


        for(i=0; i<96; i++) {
            if(freq[i][1]) printf("%d %d\n", freq[i][0]+ START, freq[i][1]);
        }

        if(fgets(line, 1010, stdin)==NULL) {nul = 0;}
        if(nul)printf("\n");
    }
    return 0;
}
