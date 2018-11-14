#include<iostream>
#include<map>
#include<queue>
#include<cstdio>
using namespace std;

struct node {
    int c;
    string n;
    node(string a, int b) {
        n = a; c = b;
    }
    friend bool operator<(node a, node b) {
        return a.c<b.c;
    }
};

int maxWeight(map<string,vector<node> > &g, string src, string des, map<string, bool> &vis) {
    int w = 20000;
    priority_queue<node> pq;
    pq.push(node(src, 20000));
    vis[src] = true;
    while(!pq.empty()) {
        node u = pq.top(); pq.pop();
        w = min(w, u.c);
        if(u.n == des) return w;
        vis[u.n] = true;
        for(int i=0; i<g[u.n].size(); i++) {
            node v = g[u.n][i];
            if( vis[v.n] == false ) {
                pq.push(node(v.n, v.c) );
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);

    int n,r, cs = 0;
    while(cin>>n>>r) {
        if(n==0 && r==0) break;

        string a, b;
        int cost;
        map<string, vector<node> > mp;
        map<string, bool> vis;
        while(r--) {
            cin>>a>>b>>cost;
            mp[a].push_back( node(b,cost) );
            mp[b].push_back(node(a,cost));
            vis[a]=false;
            vis[b]=false;
            //cout<<cost<<endl;
        }
        cin>>a>>b;
        int ans = maxWeight( mp, a, b, vis);
        cout<< "Scenario #"<<++cs<<"\n";
        cout<<ans<< " tons\n";
        cout<<"\n";
    }
    return 0;
}
