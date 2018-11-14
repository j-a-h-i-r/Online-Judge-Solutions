#include<stdio.h>

int main()
{
   // freopen("in.txt", "r", stdin);

    int t, caseno = 0;
    long n;

    scanf("%d", &t);

    while(t--){
        int i=0, len=0;
        int bin[40];
        scanf("%ld", &n);

        if(n==1) {
            printf("Case %d: 2\n", ++caseno);
            continue;
        }

        if( (n&(n-1)) ==0 ) {
            printf("Case %d: %ld\n", ++caseno, n*2);
            continue;
        }

        while(n!=0){
            bin[len++] = n%2;
            n /= 2;
            //printf("%d ", bin[len-1]);
        }
        //printf("\n%d", len);

        int j, pos=-1;

        for(i=1; i<len; i++) {
            if(bin[i-1] == 1 && bin[i]==0){
                bin[i-1] = 0;
                bin[i] = 1;
                pos = i-1;
                //for(i=0; i<len; i++) printf("%d ", bin[i]);
                break;
            }
        }
        //printf("\npos = %d\n", pos);

        if(pos==-1) {
            bin[len-1] = 0;
            bin[len] = 1;
            pos = len - 1;
            len++;
        }

        int k=0; // first zero

        for(j=pos-1; j>=k; j--) {
            if(bin[j]==1){
                for(i=k; i<j; i++) {
                    if(bin[i]==0) {
//                        int z;
//                        for(z=0; z<len; z++) printf("%d ", bin[z]);
//                        printf("\n");
//                        printf("i=%d j=%d\n", i,j);
                        bin[i] = 1;
                        bin[j] = 0;
                        k=i+1;
                        break;
                    //for(z=0; z<len; z++) printf("%d ", bin[z]);
                    //printf("\n");
                    }
                }
            }
        }

        //for(i=0; i<len; i++) printf("%d ", bin[i]);

        int ans = 0;
        for(i=0; i<len; i++) {
            //printf("%d ", bin[i]);
            ans += bin[i]*(1<<i);
        }
        printf("Case %d: %d\n",++caseno, ans);

    }

}
