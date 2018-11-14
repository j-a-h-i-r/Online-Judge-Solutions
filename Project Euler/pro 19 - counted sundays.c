#include<stdio.h>
int main()
{
    int date=6, i=1, sunday=0, year=1901, temp;
    int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    while(year<2001) {
        while(i<=12) {

            if(date==1) {
                sunday++;
                printf("%d/%d/%d\n", date,i, year);
            }
            date=date+28;

            if(date>month[i]) {

                if(i==2) {
                    if((i%400==0) || ((i%4==0) && (i%100!=0))) {
                        temp=date-29;

                    }
                    i++;
                }
                else {

                    temp=date-month[i];
                    i++;


                }
            }

            else {
                if(i==2) {
                    if((i%400==0) || ((i%4==0) && (i%100!=0))) {
                        temp=date-29+7;
                    }
                    i++;

                }
                else {
                    temp=date-month[i]+7;
                    i++;

                }
            }
            date=temp;

        }

        year++;
        i=1;
    }

    printf("%d", sunday);
}
