#include<stdio.h>
int main()
{
    int t,x,y,x1,x2,y1,y2,m,caseno=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        scanf("%d", &m);

        printf("Case %d:\n", ++caseno);

        while(m--) {
            scanf("%d %d", &x, &y);
            if( (x>x1 && x<x2) && (y>y1 && y<y2) ) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
}
