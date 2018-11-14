#include<stdio.h>
int main()
{
    /*freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);*/

    long long a,b, oa;
    int c = 0;

    while(scanf("%lld%lld", &a,&b) == 2){
        if(a<0 && b<0) break;

        oa = a;

        int count = 0;

        while(a!=1 && a<=b) {
            if(a%2==0) a = a/2;
            else a= (3*a) + 1;

            count++;
        }

        if(a == 1) count++;


        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",++c, oa, b, count);
    }
    return 0;
}

