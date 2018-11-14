#include<stdio.h>
int main()
{
    int a,b,c, lhs, rhs;

    for (c=335; c<998; c++) {
        if(c<500) {
            b=c-1;
            a=1000-(b+c);
        }
        else if (c>=500){
            a=1;
            b=1000-(a+c);
        }


        while(a<b) {

            lhs=(a*a) + (b*b);
            rhs=(c*c);
            if (lhs==rhs) {
                printf("%d %d %d\n", a,b,c);
                printf("%d", (a*b*c));
            }
            b--;
            a++;
        }
    }
}
