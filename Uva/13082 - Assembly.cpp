#include<iostream>
using namespace std;
int main()
{
    int t, cs=0;
    cin>>t;
    while(t--)
    {
        int n, st, cur=1;
        cin>>n;
        int ara[n];
        for(int i=0; i<n; i++) {
            cin>>ara[i];
            if(ara[i]==1) st= i;
        }
        for(int i=st+1; i<n; i++) {
            if( ara[i] == 1+cur )
            {
                cur = cur+1;
            }
        }
        cout<<"Case "<<++cs<<": "<<n-cur<<"\n";
    }
    return 0;
}
