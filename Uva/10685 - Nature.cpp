#include<iostream>
#include<map>
#include<cstdio>
using namespace std;

class ds{
    map<string,string> rep;
    map<string, int> tot;
public:
    ds(  ) { }

    void add( string s ) {
        rep[s] = s;
        tot[s] = 1;
    }
    void un( string a, string b ) {
        string u = find( a );
        string v = find( b );
        if( u==v ) return;
        if( tot[u] > tot[v] ) {
            // u has more animal
            // make u representative
            rep[v] = u;
            tot[u] += tot[v];
        }
        else {
            rep[u] = v;
            tot[v] += tot[u];
        }
    }
    string find( string s ) {
        if( s == rep[s] ) return s;
        rep[s] = find( rep[s] );
        return rep[s];
    }
    int largest(  ) {
        int ans = 1;
        //map<string,int>::iterator it;
        for(auto it=tot.begin(); it!=tot.end(); ++it) {
            ans = max(ans, it->second );
        }
        return ans;
    }
};

int main()
{
 //   freopen("in.txt","r",stdin);

    int n,m;
    string s, p;
    while(cin>>n>>m) {
        if( n==0 && m==0 ) break;

        ds nature;
        for(int i=0; i<n; i++) {
            cin>>s;
            nature.add(s);
        }
        for(int i=0; i<m; i++) {
            cin>>s>>p;
            nature.un(s, p);
        }
        cout<<nature.largest()<<"\n";
    }
    return 0;
}
