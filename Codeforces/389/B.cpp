#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
using namespace std;

#define ps pair<char,char>

int main()
{
    //freopen("in.txt","r",stdin);

    string a,b;
    cin>>a>>b;
    int l = a.length();

    bool vis[26];
    fill_n(vis, 26, false);
    int paired[26];
    fill_n(paired, 26, -1);

    int cnt = 0;

    for(int i=0; i<l; i++)
    {
        int x = a[i]-'a';
        int y = b[i]-'a';
        if( vis[x] ==false && vis[y]==false) {
            paired[x] = y;
            paired[y] = x;
            vis[x]=true;
            vis[y]=true;
            if(x!=y) cnt++;
        }
        else if(vis[x] ==true && vis[y]==true){
            if( paired[x]==y && paired[y]==x ) {
                // ok
            }
            else {
                cout<<-1;
                return 0;
            }
        }
        else {
            cout<<-1;
            return 0;
        }
    }

    cout<<cnt<<"\n";
    for(int i=0; i<26; i++)
    {
        if( paired[i] != i && paired[i]!= -1 ) {
            cout<< char('a'+i) << " " << char('a'+paired[i])<<"\n";
            paired[paired[i]] = -1;
        }
    }

}
