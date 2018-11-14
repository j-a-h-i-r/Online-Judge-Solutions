#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;

bool sorter( pair<int,int>a, pair<int,int> b )
{
    if( a.second == b.second )
        return a.first > b.first ;
    return a.second < b.second;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    bool flag = false;
    string s;
    while( getline(cin,s) )
    {
        if(flag) cout<<"\n";
        flag = true;
        map<char,int> mp;
        int l=s.length();
        for(int i=0; i<l; i++)
        {
            if(mp.find(s[i]) == mp.end()) mp[ s[i] ] = 1;
            else mp[ s[i] ]++;
        }
        vector<pair<int,int> > asci;

        map<char,int>::iterator it;
        for( it=mp.begin(); it!=mp.end(); ++it )
        {
            asci.push_back( make_pair(it->first, it->second) );
        }

        sort(asci.begin(), asci.end(), sorter );

        vector<pair<int,int> >::iterator iter;

        for(iter=asci.begin(); iter!=asci.end(); ++iter)
        {
            cout<<iter->first<<" "<<iter->second<<"\n";
        }
    }
    return 0;
}
