#include<stdio.h>
#include<math.h>
int main()
{
    int t,m,n,mul,knights,caseno=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &m,&n);

        if(m==1 || n==1) {
            if(m>n) knights=m;
            else knights=n;
        }

        else if(m==2 || n==2) {
            mul = m*n;

            knights = (mul/8)*4;

            if(mul%8 < 5) knights += mul%8;
            else knights += 4;
        }
        else {
            mul = m*n;

            knights = ceil(mul/2.0);

        }
        printf("Case %d: %d\n", ++caseno, knights);
    }
}
