#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        int n, x;
        int m = 0, j=0;
        cin>>n;
        while(n--)
        {
            cin>>x;
            m += ceil( double(x)/30.0)*10;
            j += ceil(double(x)/60.0)*15;

            if( x%30==0 ) m+=10;
            if( x%60==0 ) j+=15;
        }
        if( j==m)
        {
            cout<<"Case "<<++cs<<": Mile Juice "<<j<<"\n";
        }
        else {
            if(j<m) cout<<"Case "<<++cs<<": Juice "<<j<<"\n";
            else cout<<"Case "<<++cs<<": Mile "<<m<<"\n";
        }
    }
    return 0;
}
