#include<iostream>
#include<climits>
using namespace std;
int main()
{

    // This will obviously get TLE

    int n, x;
    cin>>n>>x;

    int l[n], r[n], m[n];
    for (int i=0; i<n; i++) {
        cin>>l[i]>>r[i]>>m[i];
    }
    int mnmoney = INT_MAX;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if ( (r[i]<l[j] || r[j]<l[i]) && (r[i]-l[i]+r[j]-l[j]+2)==x ) {
                if (m[i]+m[j] < mnmoney) mnmoney = m[i]+m[j];
            }
        }
    }

    if (mnmoney == INT_MAX) cout<<-1;
    else cout<<mnmoney;

    return 0;
}
