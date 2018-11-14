#include<iostream>
#include<map>
#include<cstdio>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    cin>>n;
    getchar();
    string inp, s;
    stringstream ss;
    vector<string> v;
    map<string, int> mp;
    while(n--)
    {
        getline(cin, inp);
        ss.clear();
        ss.str("");
        ss<<inp;
        ss>>s;
        if( mp.find(s)!=mp.end() ) mp[s]++;
        else {
            mp[s] = 1;
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" "<<mp[ v[i] ]<<"\n";
    }
    return 0;
}
