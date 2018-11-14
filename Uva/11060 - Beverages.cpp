#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int idx = 0, n, m;

int pos( map<string,int> &m, string st )
{
    if(m.find(st)==m.end() )
    {
        // not in map
        m[st] = idx++;
        return idx-1;
    }
    else return m[st];
}

vector<vector<int> >top (vector<int>g[], vector<int>in)
{
    int c = 0;
    vector<int> vis(n+1, 0), lev(n);
    vector<vector<int> > ret(n);
    queue<int>q;
    for(int i=0; i<n; i++)
    {
        if(in[i]==0)
        {
            q.push(i);
            lev[i] = 0;
        }
    }
    while(!q.empty() )
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if( vis[v]==0 && --in[v]==0 )
            {
                vis[v] = 1;
                lev[v] = lev[u]+1;
                q.push(v);
                //t.push_back(v);
            }
        }
        ret[lev[u]].push_back(u);
    }
    //sort(t.begin(), t.end());
    //for(int i=0; i<t.size(); i++) q.push(t[i]);
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int cs = 0;
    while(cin>>n)
    {
        idx = 0;
        map<string, int> mp;
        string s1, s2;
        vector<int> g[n+1], in(n+1, 0);
        vector<string> drinks(n);
        int u, v;
        for(int i=0; i<n; i++)
        {
            cin>>s1;
            drinks[i] = s1;
            mp[s1] = idx++;
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>s1>>s2;
            u = mp[s1];
            v = mp[s2];

            g[u].push_back(v);
            in[v]++;
            cout<<u<< "-" << v<<endl;
        }
        vector<vector<int> > ans(n);
        ans = top(g, in);

        cout<<"Case #"<<++cs<<": Dilbert should drink beverages in this order:";
        for(int i=0; i<n; i++)
        {
            sort(ans[i].begin(), ans[i].end());
            for(int j=0; j<ans[i].size(); j++)
            {
                cout<<" "<<drinks[ans[i][j]];
            }
        }
        cout<<"."<<endl;
    }
    return 0;
}
