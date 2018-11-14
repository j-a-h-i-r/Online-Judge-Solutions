#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long a[n], ans = 1;
    for(int i=0; i<n; i++) scanf("%I64d", &a[i]);

    sort(a, a+n);

    a[0] = 1;

    for(int i=1; i<n; i++) {
        long long d = a[i]-a[i-1];

        if(d>0) a[i] = a[i]-d+1;
    }

    printf("%I64d\n", a[n-1]+1 );
}
