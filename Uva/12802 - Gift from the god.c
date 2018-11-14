#include <stdio.h>
#include <math.h>

#define size 1000000
int ara[size];

void sieve()
{
    int i,j, root;

    for(i=2; i<size; i++) {
        ara[i]=1;
    }

    root=sqrt(size);
    for(i=2; i<root; i++){
        if(ara[i]==1) {
            for(j=2; i*j<size; j++) {
                ara[i*j]=0;
            }
        }
    }
}

int is_prime(int n){
    if(n<2) {
        return 1;
    }

    return ara[n];
}

int palindrome(char a[], int j) {
    int l = j-1, i;
    for(i=0; i<l; i++, l--) {
        if( a[i]!=a[l] ) return 0;
    }
    return 1;
}

int main()
{


    sieve();

   /* freopen("in.txt", "r", stdin);*/

    long int n;

    while( scanf("%ld", &n) ) {
        char s[10];
        long i = n, j=0;
        while(i) {
            s[j++] = (i%10) + '0';
            i=i/10;

        }
        s[j] = '\0';
       /* printf("%s\n", s);*/

        if (palindrome(s, j) == 1  && is_prime(n) == 1 ) {
            printf("%ld\n", 2*n);
            break;
        }
        /*printf("%d %d\n", palindrome(s,j), is_prime(n));*/

        printf("%ld\n", 2*n);
    }

    return 0;
}


