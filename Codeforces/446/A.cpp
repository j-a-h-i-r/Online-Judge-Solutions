#include<iostream>
#include<algorithm>
using namespace std;
int main()
{

    int n;
    cin>>n;

    long long int a[n], b[n];

    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0;i <n; i++) cin>>b[i];

    long long sum = 0;
    for(int i=0; i<n;i ++) sum+=a[i];

    sort(b, b+n);

    if ( sum<= b[n-1] + b[n-2] ) {
        cout<<"YES";
    }
    else cout<<"NO";

    return 0;
}
