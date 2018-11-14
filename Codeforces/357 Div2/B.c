#include<stdio.h>

#define ll long long

int main()
{
    //freopen("in.txt", "r", stdin);

    ll a=1234567, b = 123456, c= 1234;

    ll n, ans, ans2, i, j;
    int flag = 0;

    scanf("%I64d", &n);

    if(n%a == 0 || n%b==0 || n%c == 0) flag = 1;

    ans = 0;

    for(i=1; flag == 0 && ans<=n ; i++) {

        ans2 = ans;

        if( ans2>0 && n%ans2 == 0) flag = 1;

        for(j=1; ans2 <= n && flag == 0 ; j++){

            if( ( n-ans2 ) % c == 0) {
                flag = 1;
                break;
            }

            ans2 = ans + j*b;
            if(n%ans2 == 0) flag = 1;
        }

        ans = i*a;
        if(n%ans==0) flag = 1;
    }

    if(flag == 1) printf("YES\n");
    else printf("NO\n");
}
