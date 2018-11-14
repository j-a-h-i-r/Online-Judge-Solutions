#include<iostream>
using namespace std;
int main()
{
    int n,m;
    bool line = false;
    while(cin>>n>>m)
    {
        if(line) cout<<"\n"; line = true;
        if( n>m )
        {
            while(++m <= n+1) cout<<m<<"\n";
        }
        else while( ++n <= m+1 ) cout<<n<<"\n";
    }
    return 0;
}
