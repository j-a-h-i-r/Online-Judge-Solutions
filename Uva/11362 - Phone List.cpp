#include<iostream>
#include<cstdio>
using namespace std;

struct node {
    bool endMark = false;
    node *next[10];
    node() {
        for(int i=0; i<10; i++) {
            next[i] = NULL;
        }
    }
};
bool insert( node *cur, string str )
{
    bool takesNewPath = false;
    bool passedEndmark = false;
    int len = str.length();
    int id;
    for(int i=0; i<len; i++) {
        id = str[i] - '0';
        if(cur->next[id]==NULL) {
            cur->next[id] = new node();
            takesNewPath = true;
        }
        cur = cur->next[id];
        if(cur->endMark == true) passedEndmark = true;
    }
    cur->endMark = true;
    if(passedEndmark) return false;
    if(takesNewPath) return true;
    return false;
}

void free(node *cur) {
    for(int i=0; i<10; i++) {
        if( cur->next[i] != NULL ) free(cur->next[i]);
    }
    delete(cur);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    int n;
    cin>>t;
    while(t--) {
        cin>>n;
        bool cons = true;
        string str;
        node *root = new node( );
        while(n--) {
            cin>>str;
            //cout<<str<<endl;
            cons &= insert(root, str);
        }

        if(cons) cout<<"YES\n";
        else cout<<"NO\n";

        //free(root);
    }
    return 0;
}
