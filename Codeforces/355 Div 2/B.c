#include<stdio.h>
#include<math.h>

int main()
{
    freopen("in.txt", "r", stdin);

    int n, i=0;
    long long h, k, t = 0, x;
    scanf("%d%I64d%I64d", &n, &h, &k);

    long long a[n+1];

    for(i=0; i<n; i++)
    {
      scanf("%I64d", &a[i]);
    }

    long long ch = 0;

    for(i=0; i<n; i++) {

        while( ch+a[i] <= h ) {
            //ami eita nite pari
            ch = ch + a[i];
            i++;
        }

        if(i<n) x = a[i];
        else {
            x = 0;
            break;
        }

        printf("1: %lld  %lld\n", ch, x);

        if ( (ch + x) > h ) {
            long long diff = ch-h+x;

            if(diff%k==0) {
                ch = ch - diff;
                t += (diff/k);
            }
            else {
                ch -= (diff+k);
                t += (diff/k)+1;
            }
        }

        printf("2: %lld  %lld\n", ch,x);

        if(ch<0) ch = 0;
        ch = ch+x;
    }

    printf("%lld %lld\n", ch, t);

    if(ch%k==0) t += (ch/k);
    else t+= (ch/k) + 1 ;

    printf("%I64d\n", t);

    return 0;
}
