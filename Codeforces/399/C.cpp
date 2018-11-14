#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ara[n];
    int k, x, mx=-1, mn = 10000000;
    cin>>k>>x;
    for(int i=0; i<n; i++) {
        cin>>ara[i];
        mx = max(mx, ara[i]);
        mn = min(mn, ara[i]);
    }
    if(k==0) {
        cout<<mx<<" "<<mn;
        return 0;
    }

    sort(ara, ara+n);
    int mx1 = -1, mn1 = 100000000;
    while(k--) {
        sort(ara, ara+n);
        for(int i=0; i<n; i++) {
            if(i%2==0)ara[i] ^= x;
            cout<<ara[i]<<" ";
            //cout<<ara[i]<<endl;
            mx1 = max(mx1, ara[i]);
            mn1 = min(mn1, ara[i]);
        }
    cout<<endl;
    }

    sort(ara, ara+n);
    int mx2 = -1, mn2 = 1000000000;
    for(int i=0; i<n; i++) {
        if (i%2==0) ara[i]^=x;
        //cout<<ara[i]<<endl;
        mx2 = max(mx2, ara[i]);
        mn2 = min(mn2, ara[i]);
    }

    if(k%2 == 0) {
        cout<<mx2<<" "<<mn2;
    }
    else {
        cout<<mx1<<" "<<mn1;
    }
    return 0;
}
