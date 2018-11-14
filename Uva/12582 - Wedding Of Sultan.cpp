#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        stack<int> g;
        int trail[26];
        for(int i=0; i<26; i++) trail[i]=0;
        //vector<int> g[26];
        string s;
        cin>>s;
        g.push(s[0]-'A');
        for(int i=1; i<s.length()-1; i++)
        {
            int u = s[i]-'A';
            if( u == g.top() )
            {
                // back trail
                g.pop();
            }
            else {
                trail[ g.top() ]++;
                g.push(u);
                trail[u]++;
            }
        }
        cout<<"Case "<<++cs<<"\n";
        for(int i=0; i<26; i++)
        {
            if( trail[i]>0 ) cout<<char('A'+i)<<" = "<<trail[i]<<"\n";
        }
    }
    return 0;
}
