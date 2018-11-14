#include<stdio.h>

static int count[1002];
static int p [588];
static int k = 2;

void prime( )
{
    int i , j;

    p[1] = 1; count[1] = 1;
    p[2] = 2; count[2] = 2;

    for(i=3; i<=1001; i+=2)
    {
        for(j=2; j<i; j++) {
            if(i%j == 0) break;
        }
        if(j == i) {
            p[++k] = i;
            count[i-1] = k-1;
        }
        else count[i-1] = k;

        count[i] = k;
    }
}

int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/

    int n,c,i, f = 0;

    prime( );

    while(scanf("%d %d", &n, &c) == 2)
    {
        int s,e, t = c;
        if(count[n] & 1) {
            c = c*2 - 1;
            s = (count[n]+1)/2 - (c-1)/2;
            e = s + c-1;
        }
        else {
            c = c*2;
            s = (count[n]/2) - c/2 + 1;
            e = s + c-1;
        }

        if( s<1 ) s = 1;
        if(e > count[n]) e = count[n];

        printf("%d %d:", n,t);

        for(s; s<=e; s++) {
            printf(" %d", p[s]);
        }

        printf("\n\n");
    }

    return 0;
}
