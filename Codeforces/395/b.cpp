#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long ara[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>ara[i];
    }
    for(int i=1; i<=n-i; i+=2)
    {
        swap(ara[i],ara[n-(i-1)]);
    }
    for(int i=1; i<=n; i++) {
        cout<<ara[i]<<" ";
    }
    return 0;
}
