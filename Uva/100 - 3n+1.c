#include<stdio.h>
int main()
{
    freopen("in.txt", "r", stdin);

    int a,b,sum=1, max, i, sm, bg, oa;

    while(scanf("%d%d", &a,&b) == 2){
        if(a<b) {sm = a; bg = b; }
        else {sm = b; bg=a;}

        sum=1; max=0; oa = a;
        for (i=sm; i<=bg; i++) {
            a=i;
            while(a!=1) {
                if(!(a&1)) a=a/2;
                else a = (a*3)+1;
                sum++;
            }
            if(sum>max) max=sum;
            sum=1;
        }
        printf("%d %d %d\n",oa, b, max);
    }
}
