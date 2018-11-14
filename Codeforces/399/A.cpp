#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long ara[n];
    long long mx = -1, mn = 10000000000;
    for(int i=0; i<n ;i++) {
        cin>>ara[i];
        mx = max(mx, ara[i]);
        mn = min(mn, ara[i]);
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(ara[i]>mn && ara[i]<mx) cnt++;
    }
    cout<<cnt;

    return 0;
}
