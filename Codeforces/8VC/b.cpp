#include<iostream>
#include<set>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    int n,m;
    cin>>n>>m;
    set<string> ast, bst;
    map<string, int> mp;
    string a;
    for(int i=0; i<n; i++) {
        cin>>a;
        ast.insert(a);
    }
    for(int i=0; i<m; i++) {
        cin>>a;
        bst.insert(a);
    }

    set<string>::iterator ita, itb;
    bool amove = true;

    while( !ast.empty() && !bst.empty() ) {
        ita = ast.begin();
        itb = bst.begin();
        if(amove == true) {
            if(mp.find(*ita)!=mp.end() ){
                // already used;
                ast.erase(ita);
                continue;
            }
            mp[ *ita ] = 1;
            if(*ita == *itb || mp.find( *itb)!=mp.end() ) {
                bst.erase(itb);
            }
            ast.erase(ita);
            amove = false;
        }
        else {
            if(mp.find(*itb)!=mp.end()) {
                bst.erase(itb);
                continue;
            }
            mp[*itb] = 1;
            if(*ita == *itb||mp.find(*ita)!=mp.end() ) {
                ast.erase(ita);
            }
            bst.erase(itb);
            amove = true;
        }
    }
    if( ast.empty() && bst.empty() ) {
        if(amove == false) {
            cout<<"YES";
        }
        else cout<<"NO";
    }
    else if(bst.empty()) cout<<"YES";
    else cout<<"NO";
    return 0;
}
