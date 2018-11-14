#include<stdio.h>
#include<string.h>

int chkPalindrome (char str[]) {
    int i,j,length;
    char temp;

        length=strlen(str);

        for(i=0, j=length-1; i<length; i++, j--) {
            temp=str[j];                                     // assigning the last word of string to a variable
            if (temp!=str[i]) {                              // if last word and first word is not same then it's not a palindrome
                return 0;              // so print it's not palindrome

            }
        }
        if(i==length) {
            return 1;
        }
}

int main()
{
    int a,b,product,max=0;
    char str[7];
    for (a=999; a>900; a--) {
        for(b=a; b>900; b--) {
            product=a*b;
            sprintf(str, "%d", product);
            if(chkPalindrome(str)==1) {
                if(product>max) {
                    max=product;
                }
            }

        }
    }
    printf("%d", max);
}
