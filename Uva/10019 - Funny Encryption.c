#include<stdio.h>

int hexOne[] = { 0,1,1,2,1,2,2,3,1,2};

int bin(int m)
{
    int one = 0;
    while(m) {
        if(m&1) one++;
        m = m>>1;
    }
    return one;
}

int hex(int m) {
    int one = 0;

    while(m) {
        one += hexOne[m%10];
        m = m/10;
    }
    return one;
}

int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/

    int n;
    scanf("%d", &n);

    while(n--) {
        int m;
        scanf("%d", &m);

        int b = bin(m);
        int h = hex(m);

        printf("%d %d\n", b, h);
    }
    return 0;
}
