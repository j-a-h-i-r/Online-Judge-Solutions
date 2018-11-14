#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);

    //for(int i=0; i<n; i++) cout<<a[i]<<" ";
    //cout<<a[k-1];

    if (k==0) {
        if (a[0] == 1) cout<<-1;
        else cout<<a[0]-1;
    }
    else if (k <n && a[k-1] == a[k]) {
        cout<<-1;
    }
    else {
        cout<<a[k-1];
    }
}
