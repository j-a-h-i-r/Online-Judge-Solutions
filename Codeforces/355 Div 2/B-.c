#include<stdio.h>
int main()
{
    //freopen("in.txt", "r", stdin);

    int n, i=0;
    long h, k, t = 0;
    scanf("%d%ld%ld", &n, &h, &k);

    long a[n+1];

    for(i=0; i<n; i++)
    {
      scanf("%ld", &a[i]);
    }

    long ch = 0;

    for(i=0; i<n; i++) {

        while( ch+a[i] <= h ) {
            //ami eita nite pari
            ch = ch + a[i];
            i++;
        }

        long x;

        if(i<n) x = a[i];
        else {
            x = 0;
            break;
        }

        while( (ch + x) > h ) {
            ch -= k;
            t++;
        }

        if(ch<0) ch = 0;

        ch = ch+x;
    }

    while(ch>0) {
        t++;
        ch -= k;
    }

    printf("%ld\n", t);

    return 0;
}
