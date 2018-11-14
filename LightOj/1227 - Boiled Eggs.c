#include<stdio.h>
int main()
{
    int q,p,n,i=0,egg,t,caseno=0,gm,totgm=0,temp;

    scanf("%d", &t);

    while(t--) {

        scanf("%d %d %d", &n, &p, &q);
        temp = n;

        while(n--) {
            scanf("%d", &gm);
            totgm = totgm + gm;
            if(totgm <=q) {
                i++;
            }
        }
        if(totgm<=q){
            if(temp<p) egg=temp;
            else egg=p;
        }
        else {
            if(i>p) egg=p;
            else egg=i;
        }
        printf("Case %d: %d\n", ++caseno, egg);
        totgm=0;
        i=0;
    }
}
