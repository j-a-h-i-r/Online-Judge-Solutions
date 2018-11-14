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
        if( rep.find(s) == rep.end() ) {
            rep[s] = s;
            tot[s] = 1;
        }
    }
    int  un( string a, string b ) {
        string u = find( a );
        string v = find( b );
        if( u==v ) return tot[u];
        if( tot[u] > tot[v] ) {
            // u has more animal
            // make u representative
            rep[v] = u;
            tot[u] += tot[v];
            return tot[u];
        }
        else {
            rep[u] = v;
            tot[v] += tot[u];
            return tot[v];
        }
    }
    string find( string s ) {
        if( s == rep[s] ) return s;
        rep[s] = find( rep[s] );
        return rep[s];
    }
    /*int largest(  ) {
        int ans = 1;
        //map<string,int>::iterator it;
        for(auto it=tot.begin(); it!=tot.end(); ++it) {
            ans = max(ans, it->second );
        }
        return ans;
    }*/
};

int main()
{
    //freopen("in.txt","r",stdin);

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string a,b;
        ds friends;
        while(n--) {
            cin>>a>>b;
            friends.add(a); friends.add(b);
            cout<<friends.un(a,b)<<"\n";
        }
    }
    return 0;
}
