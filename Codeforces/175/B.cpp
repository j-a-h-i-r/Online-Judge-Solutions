#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;

    long ara[n];

    for (int i=0; i<n; ++i) {
        cin>>ara[i];
    }

    sort(ara, ara+n);

    long long int ans = 0;

    for (int i=0; i<n; ++i) {
        ans += abs( ara[i] - (i+1) );
    }

    cout<<ans;

    return 0;
}
