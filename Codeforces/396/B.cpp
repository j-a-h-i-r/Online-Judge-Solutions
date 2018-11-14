#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);

    for(int i=0; i<n-(3-1); i++)
    {
        if (a[i] + a[i+1] > a[i+2]) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}
