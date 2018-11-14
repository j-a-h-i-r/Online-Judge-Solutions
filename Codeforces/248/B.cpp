#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long num[n+1], sorted_num[n+1], csum[n+1], sort_csum[n+1];
    num[0] = 0;
    sorted_num[0] = 0;
    csum[0] = 0;
    sort_csum[0] = 0;

    for (int i=1; i<=n; ++i) {
        cin>>num[i];
        sorted_num[i] = num[i];
    }

    sort(sorted_num, sorted_num + n+1);

    for (int i=1; i<=n; ++i) {
        csum[i] = csum[i-1] + num[i];
        sort_csum[i] = sort_csum[i-1] + sorted_num[i];
    }

    int m;
    cin>>m;

    int t, l, r;

    for (int i=1; i<=m; ++i) {
        cin>>t>>l>>r;
        if (t==1) {
            cout<<csum[r] - csum[l-1]<<"\n";
        }
        else {
            cout<<sort_csum[r] - sort_csum[l-1]<<"\n";
        }
    }
    return 0;
}
