#include<iostream>
#include<cctype>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    string s;
    while(getline(cin, s))
    {
        int ara[127], mx = -1;
        for(int i=0; i<127; i++) ara[i] = 0;
        int l = s.length();
        for(int i=0; i<l; i++)
        {
            if( isalpha(s[i]) ) {
                ara[ s[i]]++;
                if(ara[s[i]] > mx ) mx = ara[s[i] ];
            }
        }
        for(int i='A'; i<='Z'; i++)
        {
            if( ara[i] == mx ) cout<<char(i);
        }
        for(int i='a'; i<='z'; i++)
        {
            if(ara[i]==mx) cout<<char(i);
        }
        cout<<" "<<mx<<"\n";
    }
    return 0;
}
