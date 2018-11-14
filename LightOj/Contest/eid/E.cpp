#include<iostream>
using namespace std;
int main()
{
    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;

        if( m>=n || n>=k )
        {
            if(n>=k) cout<<"case "<<++cs<<": "<<1<<endl;
            else cout<<"case "<<++cs<<": Impossible"<<endl;
        }
        else
        {
            int h = 0, d = 1;
            while( h>=0 && h<=k )
            {
                h+=n;
                if( h>=k ) break;
                d++;
                h-=m;
            }
            cout<<"case "<<++cs<<": "<<d<<endl;
        }
    }
    return 0;

}
