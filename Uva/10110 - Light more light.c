#include<stdio.h>
#define limit 65535
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int prime[7000], p = 3;
    prime[0] = 1; prime[1] = 2; prime[2] = 3;
    int i, j;
    for(i=5; i<65535; i+=2){
        int flag = 0;
        for(j=1; prime[j]*prime[j]<i; j++) {
            if(i%prime[j] == 0) {
                flag = 1;
                break;
            }
        }
        if(prime[j]*prime[j] == i) flag = 1;
        if (flag == 0) prime[p++] = i;
    }

    long long unsigned n;
    while(scanf("%llu", &n) && n!=0){
        if(n==1) {
            printf("yes\n");
            continue;
        }

        long long unsigned d = n;
        int pow, div = 1;
        for(i=1; prime[i]*prime[i]<=n && d!=1; i++) {
            pow = 0;
            while(d%prime[i]==0) {
                pow++;
                d /= prime[i];
            }
            div *= (pow+1);
        }
        if(d>1) div = div*2;
        if(div&1 == 1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
