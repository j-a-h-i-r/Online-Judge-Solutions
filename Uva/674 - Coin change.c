#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int coin[] = { 1,5,10,25,50};
const int k = 5;
long way[6][7490];

long make( int i, int n ) {
    if (i>=5) return 0;
    if(n < 0) return 0;
    if(n == 0) return 1;

    if( way[i][n] != -1 ) return way[i][n];
    else {
        way[i][n] = make(i, n-coin[i]) + make(i+1, n);
        return way[i][n];
    }
}

int main()
{
    /*//freopen("in.txt", "r", stdin);*/

    memset(way, -1, sizeof (way));

    int n;
    while(scanf("%d", &n) == 1) {
        printf("%ld\n", make(0, n));
    }
    return 0;
}
