#include<iostream>
#include<cstdio>
#include<assert.h>
using namespace std;

int tot = 0;
int numOfNode;

class node
{
    int count;
    bool endmark;
    node *next[53];
public:
    node()
    {
        endmark = false;
        count = 0;
        for(int i=0; i<53; i++)
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
            if(str[i]==' ') id = 52;
            else if(str[i]<='Z') id = str[i]-'A' + 26;
            else id = str[i] - 'a';

            if( cur->next[id] == NULL )
            {
                cur->next[id] = new node();
                ++numOfNode;
            }
            cur = cur->next[id];
        }
        cur->endmark = true;
        ++(cur->count);
    }
    void showPercent(  )
    {
        node *cur = this;
        string s = "";
        total(cur, s);
    }
    void findmax(string s) {
        node *cur = this;
        int m = -1;
        int l = s.length();
        for(int i=0; i<l; i++) {
            m = max(m,  match(i, s, l, cur) );
        }
    }
    int match(int x, string s, int len, node *cur) {
        int cnt = 0;
        for(int i=x; i<len; i++) {

        }
    }
    void total( node *cur, string s )
    {
        if( cur->endmark == true )
        {
            assert(tot >0 );
            cout.precision(4);
            cout<<s<<" "<<fixed<<100.0*((double)cur->count/(double)tot)<<"\n";
        }

        for(int i=0; i<53; i++)
        {
            if( cur->next[i] != NULL )
            {
                char ch;
                if(i==52) ch = ' ';
                else if( i<=25 ) ch = char(i+'a');
                else ch = char(i-26+'A');
                total( cur->next[i], s+ch );
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
        for(int i=0; i<53; i++)
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
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
    bool line = false;
    int t;
    cin>>t;
    string str;
    getline(cin, str);
    getline(cin, str);
    node *root= new node();
    while(t--)
    {
        tot = 0;
        numOfNode = 0;

        while ( true )
        {
            getline(cin, str);
            if( str == "" || cin.eof() )
            {
                if(cin.eof()) {
                    ++tot;
                    root->add(str);
                }

                if(line) cout<<"\n"; line = true;
                root->showPercent( );
                root->deleteAll( );
                root = new node();
                cout<<"Total nodes created "<<numOfNode<<endl;
                break;
            }
            else
            {
                ++tot;
                root->add( str );
            }
        }
    }
    return 0;
}
