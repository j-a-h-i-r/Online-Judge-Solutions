#include<stdio.h>
int main()
{
    freopen("in.txt", "r", stdin);
    int n, b, h, w, min, cost,totcost=0, bed, pos,i;

    while((scanf("%d%d%d%d", &n, &b, &h, &w)) == 4) {
        while (totcost == 0){
            while(h--) {
                pos = 1;
                i = w;
                scanf("%d", &cost);
                while (i--){
                    scanf("%d", &bed);
                    if(n>bed) {break; pos = 0; }
                }
                if (pos==1) totcost = cost*n;
                if(totcost>b) totcost=0;
            }
        }
        min = totcost;

        while(h--) {
            totcost = 0;
            pos = 1;
                i = w;
                scanf("%d", &cost);
                while (i--){
                    scanf("%d", &bed);
                    if(n>bed) {break; pos = 0; }
                }
                if (pos==1) {
                        totcost = cost*n;
                        if(min>totcost && totcost<b) min = totcost;
                }
            }
        if (totcost ==0 ) printf("stay home\n");
        else printf("%d\n", totcost);
        }
}
