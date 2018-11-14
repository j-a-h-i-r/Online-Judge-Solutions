#include<stdio.h>

const long int m = 10000007;
long a,b,c,d,e,f;
long int val[10010];

long fn(int n) {
    if(n==0) return a;
    if(n==1) return b;
    if(n==2) return c;
    if(n==3) return d;
    if(n==4) return e;
    if(n==5) return f;

    if(val[n] != -1) return val[n];
    else {
        val[n] = (fn(n-1)%m +fn(n-2)%m+fn(n-3)%m+fn(n-4)%m+fn(n-5)%m+fn(n-6)%m)%m;
        return val[n];
    }
}

int main()
{
   /* freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/

    long n;
    int t, caseNo = 0, i;

    scanf("%d", &t);
    while(t--) {
        for(i=0; i<10010; i++) val[i] = -1;
        scanf("%ld%ld%ld%ld%ld%ld%ld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %ld\n", ++caseNo, fn(n)%m);
    }
    return 0;
}
