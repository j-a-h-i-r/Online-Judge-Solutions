#include<iostream>
#include<cstdio>
using namespace std;

bool prime(int n)
{
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3; i*i<=n; i+=2)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        int ara[130];
        for(int i=0; i<130; i++) ara[i] = 0;
        for(int i=0; i<s.length(); i++)
        {
            ara[ s[i] ]++;
        }

        cout<<"Case "<<++cs<<": ";

        bool atLeastOne = false;
        for(int i=0; i<130; i++)
        {
            if( prime(ara[i]) ) {
                cout<<char(i);
                atLeastOne = true;
            }
        }
        if(!atLeastOne) cout<<"empty";

        cout<<"\n";
    }
}
