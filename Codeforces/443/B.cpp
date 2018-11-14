#include<iostream>
using namespace std;
int main()
{
    long long k;
    int n;
    cin>>n>>k;
    int ara[2*n + 1];
    int mx = -1;
    for (int i=0; i<n; i++) {
        cin>>ara[i];
        ara[n+i] = ara[i];

        mx = max(mx, ara[i]);
    }

    if (k>=(long long)(n-1)) {
        cout<<mx;
    }
    else {
        for (int i=0; i<n; i++) {
            int cnt = 0;
            for (int j=0; j<n; j++) {
                if (ara[i]==ara[j+i]) continue;
                if (ara[i]>ara[j+i])  cnt++;
                else break;
            }
            if ((long long)cnt >= k) {
                cout<<ara[i];
                return 0;
            }
        }
    }
    return 0;

}
