#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

bool vis[105];

struct node
{
    int nd, cs;
    node(int a,int b)
    {
        nd=a; cs=b;
    }
};
vector<node> g[101];

void dfs(int u, int edge, bool &found,int des)
{
    //cout<<u<<endl;
    if(u==des) {
        found = true;
        return;
    }
    vis[u]=true;
    for(int i=0; i<g[u].size(); i++) {
        if( vis[g[u][i].nd] == false  && g[u][i].cs <= edge)
        {
            dfs(g[u][i].nd, edge, found, des);
        }
    }
}
bool call_dfs(int u,int v, int edge, int n)
{
    bool found = false;
    for(int i=0; i<=n; i++) vis[i]=false;
    dfs(u, edge, found, v);
    return found;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    bool line = false;
    int c,s,q, cs=0;
    while(cin>>c>>s>>q)
    {
        if(!(c||s||q)) break;
        int u,v,d, mx=0;
        for(int i=0; i<s; i++) {
            cin>>u>>v>>d;
            //cout<<"u "<<u<<" "<<v<<endl;
            g[u].push_back(node(v,d));
            g[v].push_back(node(u,d));
            mx = max(mx, d);
        }

        int l=0,h=mx,m, ans;
        if(line) cout<<"\n"; line = true;

        cout<<"Case #"<<++cs<<"\n";

        bool tmp;

        for(int i=0; i<q; i++) {
            cin>>u>>v;
            ans = mx+1;
            l=0; h = mx;
            while(l <= h) {
                m = (l+h)/2;
                //cout<<l<<" "<<m<<" "<<h<<endl;
                tmp = call_dfs(u,v,m, c);
                if(tmp) {
                    h = m-1;
                    ans = m;
                }
                else l=m+1;
            }
            if(ans == mx+1) cout<<"no path\n";
            else cout<<ans<<"\n";
        }
        for(int i=1; i<=c; i++) g[i].clear();
    }
    return 0;
}
