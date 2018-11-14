#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ara[n+1];
    int mx = -1;
    for(int i=0; i<n; i++) {
        cin>>ara[i];
        mx = max(mx, ara[i]);
    }
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += mx-ara[i];
    }
    cout<<sum;
}
