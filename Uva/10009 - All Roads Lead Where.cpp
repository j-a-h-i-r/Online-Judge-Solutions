#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;

string bfs(map<string,vector<string> > &g, string s, string e)
{
    map<string, string> vis;
    queue<string> q;
    q.push(s);
    vis[s] = "";
    while(!q.empty())
    {
        string u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            string v = g[u][i];
            if( vis.find(v)==vis.end() )
            {
                vis[v] = u;
                q.push(v);
            }
            if( v == e ){
                //q = queue<string>();
                break;
            }
        }
    }
    string ans = "";
    ans += e[0];
    while( vis[e] != "" )
    {
        //cout<<vis[e]<<" ";
        ans += vis[e][0];
        e = vis[e];
    }
    //cout<<"\n";
    reverse( ans.begin(),ans.end() );
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);

    bool line = false;
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        int m,n;
        cin>>m>>n;
        map<string, vector<string> > g;
        while(m--)
        {
            cin>>s1>>s2;
            g[s1].push_back(s2);
            g[s2].push_back(s1);
        }

        if(line) cout<<"\n"; line = true;

        while(n--)
        {
            cin>>s1>>s2;
            //cout<<s1<<" "<<s2<<endl;
            string ans = bfs(g, s1, s2);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
