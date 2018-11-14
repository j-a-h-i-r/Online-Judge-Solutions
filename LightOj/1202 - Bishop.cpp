#include<iostream>
#include<cstdlib>
using namespace std;

bool isPossible(long x,long y, long p, long q)
{
    long nq = q - (p-x);
    if( labs( y-nq ) % 2L == 0 ) return true;
    else return false;
}

int main()
{
    int t, cs = 0;
    cin>>t;
    long r1,c1, r2,c2;
    while(t--)
    {
        cin>>r1>>c1>>r2>>c2;
        if( isPossible( r1, c1, r2, c2 ) )
        {
            if(  labs(c2-c1) == labs(r2-r1) ) cout<<"Case "<<++cs<<": 1\n";
            else cout<<"Case "<<++cs<<": 2\n";
        }
        else cout<<"Case "<<++cs<<": impossible\n";
    }
    return 0;
}
