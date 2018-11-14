#include<iostream>
#include<cstdio>
#include<assert.h>
using namespace std;

int mx;

class node
{
    int count;
    bool endmark;
    node *next[2];
public:
    node()
    {
        endmark = false;
        count = 0;
        for(int i=0; i<2; i++)
        {
            this->next[i] = NULL;
        }
    }
    void add(string str)
    {
        node *cur = this;

        int l = str.length();
        int id;
        for(int i=0; i<l; i++)
        {
            id = str[i] - '0';

            if( cur->next[id] == NULL )
            {
                cur->next[id] = new node();
            }
            cur = cur->next[id];
            ++(cur->count);
        }
        cur->endmark = true;
    }
    void getPrefixGoodness(  )
    {
        node *cur = this;
        int prefixLen = 0;
        total(cur, prefixLen);
    }
    void total( node *cur, int len )
    {
        if( cur->endmark == true ) mx = max(mx, len*cur->count );
        for(int i=0; i<2; i++)
        {
            if( cur->next[i] != NULL )
            {
                mx = max(mx, len*cur->count);
                //cout<<len<<" "<<cur->count<<" "<<len*cur->count<<endl;
                total( cur->next[i], len+1 );
            }
        }
    }
    void deleteAll( )
    {
        node *cur = this;
        del( cur );
    }
    void del( node *cur )
    {
        for(int i=0; i<2; i++)
        {
            if( cur->next[i] != NULL )
            {
                del(cur->next[i]);
            }
        }
        delete(cur);
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w", stdout);
    bool line = false;
    int t, n;
    cin>>t;
    string str;

    while(t--)
    {
        node *root= new node();

        mx = 0;

        cin>>n;

        while(n--) {
            cin>>str;
            root->add(str);
        }
        root->getPrefixGoodness();
        cout<<mx<<"\n";
        root->deleteAll();
    }
    return 0;
}
