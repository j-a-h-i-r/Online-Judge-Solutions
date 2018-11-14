#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char y[1000];
    int s = 0;
    while((scanf("%s", y)) !=EOF ) {
        if(s!=0) printf("\n"); s = 1;

        int three=0, four=0, five=0, fiftyFive=0, eleven=0, hun=0, fourHun=0;
        int l = strlen(y), num, i;

        if(y[l-1] == '0' && y[l-2] == '0') hun = 1;
        num = (y[l-2]-'0')*10+(y[l-1]-'0');
        if(num%4 == 0) {
            four = 1;
            num+=(y[l-4]-'0')*1000+(y[l-3]-'0')*100;

            if(num%400==0) fourHun=1;
        }
        if(y[l-1]=='0'||y[l-1]=='5') five=1;
        int odd=0, even=0;
        for(i=0; i<l; i+=2){
            odd+=(y[i]-'0');
        }
        for(i=1; i<l; i+=2) {
            even+=(y[i]-'0');
        }

        if((abs(odd-even)) % 11 == 0) eleven =1;
        if((odd+even)%3== 0) three=1;

        if((four && !hun) || fourHun) {
            printf("This is leap year.\n");
            if(five && three) printf("This is huluculu festival year.\n");
            if(five && eleven) printf("This is bulukulu festival year.\n");
        }
        else if(five && three) printf("This is huluculu festival year.\n");
        else printf("This is an ordinary year.\n");

    }
    return 0;
}
