#include<stdio.h>
int main()
{
    int t, c = 0;
    scanf("%d", &t);
    getchar();

    while(t--) {
        int n, tie = 0, bd = 0, www = 0, abn = 0;
        scanf("%d", &n);
        getchar();
        int i;
        char ch;
        for(i=0; i<n; i++) {
            scanf("%c", &ch);
            if(ch == 'B') bd++;
            else if(ch == 'W') www++;
            else if(ch == 'T') tie++;
            else if(ch == 'A') abn++;
        }
        getchar();

        if(abn == n) {
            printf("Case %d: ABANDONED\n", ++c);
        }
        else {
            n = n - abn;
            if(bd==n) {
                printf("Case %d: BANGLAWASH\n", ++c);
            }
            else if(www == n) {
                printf("Case %d: WHITEWASH\n", ++c);
            }
            else if(bd>www) {
                printf("Case %d: BANGLADESH %d - %d\n", ++c, bd, www);
            }
            else if(www>bd) {
                printf("Case %d: WWW %d - %d\n", ++c, www, bd);
            }
            else if(bd==www) {
                printf("Case %d: DRAW %d %d\n", ++c, bd, tie);
            }
        }
    }
    return 0;
}
