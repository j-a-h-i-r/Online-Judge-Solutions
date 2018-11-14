#include<stdio.h>
int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);*/

    int coef[500], x[500];
    unsigned int digit;
    int num = 0,  readingCoef = 1, i=0, j=0, sign=1;

    while( digit = getchar() )
    {
        if(digit==EOF) break;

        /* reading a digit char by char
         now need to read till {space} and convert it to a number;*/
        if(digit==' ' || digit =='\n')
        {
            if(readingCoef == 1) coef[i++] = num*sign;
            else x[j++] = num*sign;

            num = 0;
            sign = 1;

            if(digit=='\n')
            {
                readingCoef = 1 - readingCoef; /*toggling value*/

                if(readingCoef == 1) /* completed reading all {x} values*/
                {
                    int spaceFlag = 1;
                    /* do what is told;*/
                    int x_j, a_i;

                    for(x_j=0; x_j < j; x_j++)
                    {
                        long long int poly = coef[i-1], mul=x[x_j];

                        for(a_i=i-2; a_i >= 0; a_i--)
                        {
                            poly += coef[a_i]*mul;
                            mul *= x[x_j];
                        }
                        if(spaceFlag == 1) { printf("%lld", poly); spaceFlag = 0; }
                        else printf(" %lld", poly);
                    }
                    printf("\n");

                    i=0;
                    j=0;
                }
            }
        }

/*         have not encountered any {space} or {newLine}. so turn the digit
         into number*/

        else if(digit=='-') sign=-1;
        else num = num*10 + (digit-'0');
    }
    return 0;
}
