#include<stdio.h>
int main()
{
    freopen("in.txt", "r", stdin);

    int t,c=0;
    long long int d;
    long long unsigned b;
    char a[250];

    scanf("%d", &t);

    while(t--){
        scanf("%s%llu", a, &d);

        if(d<0) b=-d;
        else b=d;

        int i;
        long long unsigned mod=0;

        if(a[0]=='0' && a[1]=='\0') {
            printf("Case %d: divisible\n", ++c);
            continue;
        }

        if(a[0]=='-') i=1;
        else i=0;

        for( ; a[i]!='\0'; i++){
            mod = mod*10 + (a[i]-'0');
            mod = mod%b;
        }
        if(mod==0) printf("Case %d: divisible\n", ++c);
        else printf("Case %d: not divisible\n", ++c);
    }
}
