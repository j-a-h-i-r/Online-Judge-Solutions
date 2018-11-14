#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    map<char, int> mp;
    mp['B']=1;mp['F']=1;mp['P']=1;mp['V']=1;
    mp['C']=2;mp['G']=2;mp['J']=2;mp['K']=2;
    mp['Q']=2;mp['S']=2;mp['X']=2;mp['Z']=2;
    mp['D']=3;mp['T']=3;
    mp['L']=4;
    mp['M']=5;mp['N']=5;
    mp['R']=6;

    string s;
    while(cin>>s)
    {
        int prev = -1;
        int l= s.length();
        for(int i=0; i<l; i++)
        {
            if( mp.find(s[i])!=mp.end() )
            {
                if( prev != mp[s[i]] )
                {
                    cout<<mp[ s[i] ];
                    prev=mp[s[i]];
                }
            }
            else prev = -1;
        }
        cout<<"\n";
    }
    return 0;
}
