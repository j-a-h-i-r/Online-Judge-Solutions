#include<iostream>
#include<map>
//#include<cstdio>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int m, n;
    map<string, string> mp;
    cin>>m>>n;

    while(n--) {
        string a, b;
        cin>>a>>b;

        mp[a] = b;
    }

    while(m--) {
        string x;
        cin>>x;

        if( x.length() <= mp[x].length() ) cout<<x<< " ";
        else cout<<mp[x]<< " ";
    }

    return 0;
}
