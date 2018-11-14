#include<stdio.h>
int main()
{
    long long int d;
    while(scanf("%lld", &d) && d!=0) {
        int p=0, i=0, j=0;
        char b[100];
        while(d) {

            if(d&1) {
                p++;
                b[i++] = '1';
            }
            else b[i++] = '0';
            d = d>>1;
        }
        b[i] = '\0';
        for(j=0, i=i-1; j<i; j++, i--){
            char c;
            c = b[j];
            b[j] = b[i];
            b[i] = c;
        }
        printf("The parity of %s is %d (mod 2).\n", b, p);
    }
    return 0;
}
