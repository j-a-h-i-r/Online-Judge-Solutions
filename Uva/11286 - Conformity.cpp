#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s;
    int t;
    while(cin>>t)
    {
        if(t==0) break;
        int mx = 1;
        int pep = t;
        queue<string> q;
        map<string,int> mp;
        while(t--)
        {
            vector<string> vs;
            for(int i=0; i<5; i++)
            {
                cin>>s;
                vs.push_back(s);
            }
            sort(vs.begin(), vs.end());

            string line = "";
            for(int i=0; i<5; i++) line+=vs[i];

            if(mp.find(line)!=mp.end())
            {
                mp[line]++;
                if( mp[line] > mx ) mx = mp[line];
            }
            else {
                mp[line] = 1;
            }
        }
        bool flag = true;
        int sum = 0;
        map<string,int>::iterator it;
        for(it=mp.begin(); it!=mp.end(); ++it)
        {
            if( it->second == mx ) sum += mx;
        }

        cout<<sum<<"\n";
    }
    return 0;
}
