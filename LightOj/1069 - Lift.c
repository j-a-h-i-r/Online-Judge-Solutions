#include<stdio.h>
int main()
{
    int t,mypos,liftpos,caseno=0,time;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &mypos, &liftpos);
        if(liftpos>=mypos) {
            time = (liftpos*4) + 19;
        }
        else {
            time = (mypos*4) + 19 + (mypos-liftpos)*4;
        }

        printf("Case %d: %d\n", ++caseno, time);
    }
}
