#include<stdio.h>
#include<math.h>
int main()
{
    int t,x,y,root,caseno=0;
    long long int time, square;

    scanf("%d", &t);

    while(t--) {
        scanf("%lld", &time);

        root = sqrt(time);
        square = pow(root, 2);

        if(root%2==0) {
            if(time == square) {    // perfect square
                x=root; y=1;
            }

            else if(time <= (square+root+1) ) {  // less than corner
                x=root+1; y = time-square;
            }

            else {      // more than corner
                x=pow(root+1, 2) - time +1;
                y=root+1;
            }

        }

        else {      // sqrt odd
            if(time==square) {
                x=1; y=root;
            }

            else if(time <= (square+root+1) ) {  // less than corner
                x=time-square; y = root+1;
            }

            else {      // more than corner
                x=root+1;
                y=pow(root+1, 2) - time +1;
            }
        }

        printf("Case %d: %d %d\n", ++caseno, x,y);

    }
}
