#include<stdio.h>

int leap(long a)
{
    if( (a%4==0 && a%100!=0) || (a%400 == 0) ) return 1;
    return 0;
}

int main()
{
    long y;
    scanf("%ld", &y);

    long rem = 0;

    long y2 = y;
    long day;

    while( 1 )
    {
        y2++;
        if(leap(y2)) day = 366;
        else day = 365;

        rem = (rem + (day%7))%7;

        if(rem == 0 && (leap(y)==leap(y2) ) )
        {
            //printf("%ld %ld\n", y, y2);

            break;
        }
    }

    printf("%ld\n", y2);
}
