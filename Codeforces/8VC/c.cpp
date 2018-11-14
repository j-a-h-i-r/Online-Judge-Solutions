#include<iostream>
#include<set>
#include<cstdio>
using namespace std;

class ds{
    int ara[10005];

public:
    ds(int n) {
        for(int i=1; i<=n; i++) {
            ara[i]=i;
            //cout<<ara[i]<<endl;
        }
    }
    void un(int a, int b) {
        int u = find(a);
        int v = find(b);
        if(u==v) return;
        //if( u<v ) swap(u,v);
        ara[u] = v;
    }
    int find( int a ) {
        if( ara[a] == a ) return a;
        ara[a] = find( ara[a] );
        return ara[a];
    }
    int trees( int n ) {
        set<int> st;
        for(int i=1; i<=n; i++) {
            st.insert(ara[i]);
        }
        return st.size();
    }
};

int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    cin>>n;
    int x;
    ds forest(n);
    for(int i=1; i<=n; i++) {
        cin>>x;
        //cout<<x<<endl;
        forest.un(i,x);
    }
    for(int i=1; i<=n; i++) {
        forest.find(i);
    }
    cout<<forest.trees(n);
    return 0;
}
