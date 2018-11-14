#include<stdio.h>

int f91(int n){
    if (n>=90) return n-10;
    else return f91(n+11);
}

int main()
{
    freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);
    int n;
    while(scanf("%d", &n)==1 && n!=0 ) {
        printf("f91(%d) = %d\n", n, f91(n));
    }
    return 0;
}
