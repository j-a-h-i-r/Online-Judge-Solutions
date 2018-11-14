#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

int bfs(string src, string des, map<string, vector<string> > &g, map<string,int> dist )
{
    dist[src] = 0;
    queue<string> q;
    q.push(src);
    while(!q.empty())
    {
        string u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            string v = g[u][i];
            if( dist[v] == -1 )
            {
                dist[v] = dist[u]+1;
                q.push(v);
                if(v==des) return dist[v];
            }
        }
    }
    return -1;
}

int main()
{
    freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout );

    cout<<"SHIPPING ROUTES OUTPUT\n\n";

    int t, cs = 1;
    cin>>t;
    while(t--)
    {
        cout<<"DATA SET  "<<cs++<<"\n\n";

        string a,b;
        int m,n,p;
        cin>>m>>n>>p;
        map<string, vector<string> > mp;
        map<string, int> d;

        while(m--) {
            cin>>a;
            d[a] = -1;
        }

        while(n--)
        {
            cin>>a>>b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        int c;
        while(p--)
        {
            cin>>c>>a>>b;
            int leg = bfs(a,b, mp, d);
            if(leg == -1)
            {
                cout<<"NO SHIPMENT POSSIBLE\n";
            }
            else cout<<"$"<<leg*100*c<<"\n";
        }
        cout<<"\n";
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
