#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

map<string,int> dist;

map<string,string> bfs(string src,string des, map<string,vector<string> > &g)
{
    map<string,string> par;
    dist[src] = 0;
    par[src] = "";
    par[des] = "";
    queue<string> q;
    q.push(src);
    while(!q.empty())
    {
        string u=q.front(); q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            string v = g[u][i];
            if(dist[v]==-1)
            {
                par[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
                if( v == des ) return par;
            }
        }
    }
    return par;
}

int main()
{
    int n;
    bool flag = false;
    while(cin>>n)
    {
        if(flag) cout<<"\n";
        flag = true;

        map<string, vector<string> > g;
        string a,b;

        while(n--) {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
            dist[a] = -1;
            dist[b] = -1;
            //cout<<g[a][0]<<"\n"<<g[b][0]<<"\n";
        }
        string s,d;
        cin>>s>>d;

        map<string,string> path = bfs(s,d, g);

        stack< pair<string,string> > p;
        //p.push( make_pair(path[d],d) );

        while( path[d] != "" )
        {
            p.push( make_pair(path[d], d ));
            d = path[d];
        }

        if( p.empty() )
        {
            cout<<"No route\n";
            continue;
        }

        while(!p.empty())
        {
            cout<<p.top().first<<" "<<p.top().second<<"\n";
            p.pop();
        }
    }
    return 0;
}
