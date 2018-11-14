#include<stdio.h>
int main()
{
    int t,caseno=0,a,b,c,answer;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d", &a,&b,&c);

        if(a>b && a>c) answer = (b*b) + (c*c) - (a*a);
        else if(b>a && b>c) answer = (c*c) + (a*a) - (b*b) ;
        else answer = (b*b) + (a*a) - (c*c);

        if(answer==0) printf("Case %d: yes\n", ++caseno);
        else printf("Case %d: no\n", ++caseno);
    }

}
