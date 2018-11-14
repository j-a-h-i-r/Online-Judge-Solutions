#include<iostream>
#include<map>
#include<sstream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    stringstream ss;
    map<string,string> mp;
    string inp, english, foreign;
    while(getline(cin,inp))
    {
        if(inp=="") break;
        ss.clear();
        ss.str("");
        ss<<inp;
        ss>>english>>foreign;
        mp[foreign] = english;
    }
    string query;
    while(cin>>query)
    {
        if(mp.find(query)!=mp.end())
        {
            cout<<mp[query]<<"\n";
        }
        else cout<<"eh\n";
    }
    return 0;
}
