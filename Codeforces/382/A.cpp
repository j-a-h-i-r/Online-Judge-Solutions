#include<iostream>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int g, t;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='G') g = i;
        if(s[i]=='T') t = i;
    }
    int dis = max(g,t) - min(g,t);
    if( dis%k == 0  )
    {
        for(int i=min(g,t); i<=max(g,t); i+=k )
        {
            if( s[i] == '#' ) {
                cout<<"NO\n";
                return 0;
            }
        }
    }
    else {
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";

    return 0;
}
