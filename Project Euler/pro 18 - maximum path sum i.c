#include<stdio.h>

int main()
{
    int a,b,line,column, pp=0, sum, junk;

    FILE *fp = fopen("pro18.txt", "r");

    fscanf(fp, "%d", &sum);

    printf("%d  ", sum);

    for(line = 1; ; line++) {

        for(column = 0; column<=line; column++) {

            if(column==pp) {        // encountered first adjacent

                fscanf(fp, "%d %d", &a, &b);

                if(a>b) {
                    printf("%d  ", a);

                    pp=column;

                    sum+=a;
                }
                else{
                    printf("%d  ", b);

                    pp=column+1;

                    sum+=b;

                }

                column++;
            }

            else if(fscanf(fp, "%d", &junk) !=1) {
                line=-1;
                break;

            }
        }

        if(line == -1) break;
    }
    printf("%d", sum);
}
