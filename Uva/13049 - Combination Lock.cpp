#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        int n;
        string a,b;
        cin>>n>>a>>b;
        int step = 0;
        for(int i=0; i<n; i++)
        {
            int diff = abs( a[i] - b[i] );
            step += min( diff, 10-diff );
        }
        cout<<"Case "<<++cs<<": "<<step<<"\n";
    }
    return 0;
}
