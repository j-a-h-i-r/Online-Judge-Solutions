#include<iostream>
#include<cmath>
using namespace std;
int main()
{
        long long int n,m, k;
        cin>>n>>m>>k;

        long long tot;
        long long  mx = max(k, n-k+1);
        long long  mn = min(k, n-k+1) - 1;

        tot = mx*(mx+1)/2;
        tot += (mn*mx) - (mn*(mn+1)/2);

        //cout<<tot<<endl;

        if(  tot<= m ) {
            // see if i can increase it;
            long long rem = m - tot;
            mx += (long long)floor( double(rem)/double(n) );
            cout<<mx;
        }
        else {
            long long rem = tot - m;
            long long a = ceil( double(rem)/double(n) );
            mx -= a;
            cout<<mx;
        }
    return 0;
}
