#include<stdio.h>
#include<string.h>

int min(int x, int y){
    if(x<y) return x;
    else return y;
}

int main()
{
    char a[15], b[15];

    while(scanf("%s %s", a,b) ==2){

        int i = strlen(a) - 1, j = strlen(b) - 1;

        if( i == 0 && j == 0 && a[0]=='0' && b[0]=='0' ) break;

        int c = 0, cc=0, x;

        int m = min(i,j);

        for (x = 0; x<=m; x++) {
            if ( (a[i]-'0') + (b[j]-'0') + c >= 10 ) {
                cc++;
                c = 1;
            }
            else c = 0;

            i--; j--;
        }

        if(i!=j){
            if(i==-1) {
                for(j; j>=0; j--){
                    if( (b[j]-'0') + c >= 10 ) {
                        cc++;
                        c=1;
                    }
                    else break;
                }
            }
            else if(j==-1) {
                for(i; i>=0; i--){
                    if( (a[i]-'0') + c >= 10 ) {
                        cc++;
                        c=1;
                    }
                    else break;
                }
            }
        }

        if(cc == 0){
            printf("No carry operation.\n");
        }
        else{
            if(cc==1) printf("1 carry operation.\n");
            else printf("%d carry operations.\n", cc);
        }
    }
    return 0;
}
