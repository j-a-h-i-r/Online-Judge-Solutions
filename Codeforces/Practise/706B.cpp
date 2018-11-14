#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int n;

int shops(int a, vector<int> &vec)
{
    int lo = 0, hi = n-1, mid, pos=-1;

    while(lo<=hi) {
        mid = (lo+hi)/2;
        if ( vec[mid] <= a ) {
            //lo = mid;
            pos = mid;
            lo = mid + 1;
            //cout<<"p "<<pos<<endl;
        }
        else {
            hi = mid - 1;
        }
    }
    return pos;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int q, x;
    cin>>n;
    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin>>x;
        vec[i] = x;
    }
    sort(vec.begin(), vec.end());
    //for (int i=0; i<n; i++) cout<<vec[i]<<" ";
    //cout<<endl;
    cin>>q;

    for (int i=0; i<q; i++) {
        cin>>x;
        int ans = shops(x, vec);
        cout<<ans+1<<endl;
    }

    return 0;
}
