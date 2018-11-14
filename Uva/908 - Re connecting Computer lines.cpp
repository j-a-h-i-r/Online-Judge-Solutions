#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node{
    int cost, u,v;
    node(int a, int b, int c) {
        cost = a; u = b; v = c;
    }
    friend bool operator<(node a, node b) {
        return a.cost < b.cost;
    }
};

static int rep[1000001];
static int tot[1000001];

class ds{
public:
    ds( int n ) {
        for(int i=0; i<=n; i++) {
            rep[i] = i;
            tot[i] = 1;
        }
    }

    int  un( int a, int b ) {
        int u = find( a );
        int v = find( b );
        if( u==v ) return -1;
        if( tot[u] > tot[v] ) {
            // make u representative
            rep[v] = u;
            tot[u] += tot[v];
            return 1;
        }
        else {
            rep[u] = v;
            tot[v] += tot[u];
            return 1;
        }
    }
    int find( int s ) {
        if( s == rep[s] ) return s;
        rep[s] = find( rep[s] );
        return rep[s];
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);

    bool line = false;
    int n, m, t, k, u,v,c;
    while(cin>>n) {
        int tot = 0, alt_tot = 0;
        vector<int> g[n+1];
        vector<node> edges;
        for(int i=1; i<n; i++) {
            cin>>u>>v>>c;
            edges.push_back( node(c, u, v) );
            tot += c;
        }
        cin>>k;
        for(int i=0; i<k; i++) {
            cin>>u>>v>>c;
            edges.push_back(node(c, u,v));
        }
        cin>>m;
        for(int i=0; i<m; i++) {
            cin>>u>>v>>c;
            // discard
        }
        // got all edges required
        // sort it
        ds st(n+k);
        sort(edges.begin(), edges.end() );
        for(int i=0; i<edges.size(); i++) {
            c = edges[i].cost;
            u = edges[i].u;
            v = edges[i].v;

            if( st.un(u , v) == -1 ) {
                // already in same forest
                // discard
            }
            else {
                st.un(u, v);
                alt_tot += c;
            }
        }
        if(line) cout<<"\n"; line = true;
        cout<<tot<<"\n"<<alt_tot<<"\n";
    }
    return 0;
}
