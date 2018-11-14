#include <stdio.h>
#include <string.h>

char *numberToWord (int n, int m) {
    char word[5][10][20]={{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}, {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}, {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" }, {"", "onehundredand", "twohundredand", "threehundredand", "fourhundredand", "fivehundredand", "sixhundredand", "sevenhundredand", "eighthundredand", "ninehundredand" }, {"", "onethousnad", "","","","","","","",""} };
    return word[n][m];

}

int main()
{
    char string[30];
    int number=1, pos=1, digit,i, firstDigit, secondDigit,sum=0;
    while(number<=1000) {
        pos=1;
        i=number;
        firstDigit=number%10;
        secondDigit= (number/10)%10;
        while( i>0 ) {
            digit=i%10;
            if(secondDigit==1) {
                strcpy(string, numberToWord(0, firstDigit));
                ++pos;
                secondDigit=0;
                i=i/10;
            }
            else {
                strcpy(string, numberToWord(pos, digit));
            }
            printf("%s\n", string);
            sum=sum+strlen(string);


            i=i/10;
            pos++;
        }
        number++;

        printf("\n");
    }
    printf("%d", sum);

}
