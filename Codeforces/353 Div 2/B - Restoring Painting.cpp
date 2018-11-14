#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n, a, b, c, d;
    long long sum[4];
    cin>>n>>a>>b>>c>>d;

    sum[0] = a+b;
    sum[1] = a+c;
    sum[2] = b+d;
    sum[3] = c+d;

    sort(sum, sum+4);

    long long diff = sum[3] - sum[0];

    if(diff>n) cout<<0<<endl;

    else {
        long long ans = (n-diff)*n;

        cout<<ans<<endl;
    }

    return 0;
}
