#include<iostream>
using namespace std;
int f(long long ara[], long long num, int n) {
    int lo = 1, hi = n;
    int mid;
    while(ara[lo] < num) {
        mid = (lo+hi)/2;
        if (ara[mid] > num) {
            hi = mid-1;
        }
        else if(ara[mid] < num) {
            lo = mid + 1;
        }
        else {
            hi = hi + 1;
        }
    }
    return lo;
}
int main()
{
    int n, m;
    cin>>n>>m;
    long long csum[n+1];
    long long num;
    csum[0] = 0;
    for(int i=1; i<=n; i++) {
        cin>>num;
        csum[i] = num + csum[i-1];
    }
    for(int i=0; i<m; i++) {
        cin>>num;
        int dorm = f(csum, num, n);
        long long room = num - csum[dorm-1];
        cout<<dorm<<" "<<room<<"\n";
    }
    return 0;
}
