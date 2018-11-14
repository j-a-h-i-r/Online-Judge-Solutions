#include<iostream>
#include<vector>
#include<set>
#include<cstdio>
using namespace std;

class ds{
    vector<int> par;
    int sz;
public:
    ds(int n) {
        for(int i=0; i<n; i++) {
            par.push_back(i);
        }
        sz = n;
    }
    void un(int a, int b) {
        int u = find(a);
        int v = find(b);
        if(u==v) return;
        par[v] = u;
    }
    int find( int a ) {
        if( par[a] == a ) return a;
        par[a] = find( par[a] );
        return par[a];
    }
    int totComp(  ){
        update(sz);
        set<int> st;
        for(int i=0; i<sz; i++) {
            st.insert( par[i] );
        }
        return st.size();
    }
    void update(int n) {
        for(int i=0; i<n; i++) {
            find( i );
        }
    }
};

int l2n(char a) {
    return int( a-'A' );
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    cin>>t;

    cin.clear();
    getchar();
    getchar();

    while(t--) {
        char c;
        cin>>c;
        getchar();

        char s[5];
        vector<int> v[26];
        ds graph( l2n(c) + 1 );
        while(fgets(s, 4, stdin) )
        {
            if(s[0] == '\n') break;

            int i = l2n(s[0]),  j = l2n(s[1]);
            graph.un(i,j);
        }
        cout<<graph.totComp()<<endl;
        if(t) cout<<endl;
    }
}
