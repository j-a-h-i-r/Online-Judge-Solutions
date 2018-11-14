#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x;
    int b[10];
    for (int i=0; i<10; i++) {
        b[i] = 0;
    }
    cin>>n>>m;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    for (int i=0; i<m; i++) {
        cin>>x;
        b[x] = 1;
    }

    for (int i=0; i<n; i++) {
        if (b[ a[i] ]) cout<<a[i]<<" ";
    }
    return 0;
}
