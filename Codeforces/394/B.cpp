#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);

    int n, l;
    cin>>n>>l;
    if(n==1) cout<<"YES";
    else {
        int a[n+1], b[n+1];
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        for(int i=0; i<n; i++) {
            cin>>b[i];
        }
        int ca[n+1], cb[n+1];

        for(int i=1; i<n; i++) {
            ca[i] = a[i]-a[i-1];
            cb[i] = b[i]-b[i-1];
        }
        int ad, bd;
        for(int i=0; i<n; i++) {
            int diff = 0;
            for(int j=1; j<n; j++) {
                if( ca[j] != cb[ (j+i-1)%(n-1) + 1] ) {
                    // does not match
                    diff++;
                    ad = ca[j];
                    bd = cb[(j+i-1)%(n-1)+1];
                }
            }
            cout<<i<<" "<<diff<<endl;
            for(int k=1; k<n; k++) {
                    cout<<ca[k]<<" ";
                }
                cout<<endl;
                for(int k=1; k<n; k++) {
                    cout<<cb[ (k+i-1)%(n-1) + 1 ]<<" ";
                }
            cout<<endl;
            if(diff==0) {
                cout<<"YES";
                return 0;
            }
            if(diff<=1) {
                // it might be same
                int ax = a[0]+(l-a[n-1]);
                int bx = b[0]+(l-b[n-1]);
                if(ax==bd && bx==ad) {
                    cout<<"YES";
                    return 0;
                }
            }
        }
        cout<<"NO";
    }
    return 0;
}
