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

    int z = min(100 + k%2, k);

    while(z--) {
        sort(ara, ara+n);
        for(int i=0; i<n; i++) {
            if(i%2==0)ara[i] ^= x;
            //cout<<ara[i]<<" ";
            //cout<<ara[i]<<endl;
            //mx1 = max(mx1, ara[i]);
            //mn1 = min(mn1, ara[i]);
        }
    }
    for(int i=0; i<n; i++) {
        mx1 = max(mx1, ara[i]);
        mn1 = min(mn1, ara[i]);
    }

    cout<<mx1<<" "<<mn1<<"\n";

    return 0;
}

