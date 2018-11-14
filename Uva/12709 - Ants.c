#include<stdio.h>
int main()
{
    int t;

    while(scanf("%d", &t)) {
        if(t==0) break;

        int l, w, h, v, preH;

        scanf("%d%d%d", &l, &w, &h);

        preH = h;
        v = l*w*h;

        while(--t) {
            scanf("%d%d%d", &l, &w, &h);
            if(h > preH) {
                v = l*w*h;
                preH = h;
            }
            else if(h == preH) {
                if( (l*w*h) > v ) v = l*w*h;
            }
        }

        printf("%d\n", v);
    }
    return 0;
}
