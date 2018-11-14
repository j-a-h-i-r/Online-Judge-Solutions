#include<iostream>
using namespace std;
int main()
{
    int n,k;
    bool parbe = false;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int x;
    for(int i=0; i<k; i++) {
        cin>>x;
    }
    if (k>1) {
        parbe = true;
    }
    else {
        for(int i=0; i<n && a[i]!=0; i++) {
            if(a[i]>x) {
                parbe = true;
                break;
            }
        }
    }

    if(parbe) cout<<"Yes";
    else cout<<"No";
    return 0;
}
