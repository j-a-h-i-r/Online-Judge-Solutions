#include<stdio.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);

    while(t--) {
        int r;
        scanf("%d", &r);

        int l = r*5, w = r*3;

        int tlX = 0 - ((l/20)*9);
        int tlY = 0 + (w/2);
        int trX = 0 + ((l/20)*11);
        int trY = 0 + (w/2);
        int blX = 0 - ((l/20)*9);
        int blY = 0 - (w/2);
        int brX = 0 + ((l/20)*11);
        int brY = 0 - (w/2);

        printf("Case %d:\n", ++c);
        printf("%d %d\n", tlX, tlY);
        printf("%d %d\n", trX, trY);
        printf("%d %d\n", brX, brY);
        printf("%d %d\n", blX, blY);
    }
    return 0;
}
