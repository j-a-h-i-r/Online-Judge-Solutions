#include<iostream>
#include<map>
#include<queue>
#include<sstream>
#include<cstdio>
using namespace std;

int bfs(string src, string des, map<string,int> g)
{
    //cout<<src<<" "<<des<<"\n";
    queue<string> q;
    q.push(src);
    g[src] = 0;

    int l = src.length();

    while(!q.empty() )
    {
        string u = q.front(); q.pop();
        string ns = u;
        for(int i=0; i<l; i++)
        {
            ns = u;     // reset the array so that we take only one changed char at a position
            for(int j=0; j<26; j++)
            {
                ns[i] = j + 'a'; // change one char of array
                //cout<<ns<<" ";
                //cout<<ns<<"\n";
                if( g.find(ns) != g.end() ) // this new word is part of dictionary
                {
                    //cout<<ns<<"\n";
                    if( g[ns] == -1 )       // it's still unvisited
                    {
                        g[ns] = g[u] + 1;   // increase its length by 1
                        q.push(ns);         // push it to quueu to explore words that can be found from it

                        if(ns == des) return g[ns];     //found ans return it;
                    }
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin );

    int n;
    bool flag = false;
    cin>>n;
    //cout<<n;
    while(n--)
    {
        if(flag) cout<<"\n";
        flag = true;

        map<string,int> g;
        string a;
        while(cin>>a)           // read words and make a dictionary
        {
            //cout<<a<<"\n";
            if(a=="*") break;
            g[a] = -1;          // init set all values to -1
                                // with this I can explore the words without using visited map
        }
        cin.ignore();           // clear the newline character

        string s,d, inp;
        stringstream ss;
        int path;
        while( getline(cin, inp) )  // reading the input stream
        {
            ss.clear();          // clear stringstream, otherwise it will store the previouse value
            ss.str("");
            ss.str(inp);
            if( ss.rdbuf()->in_avail() == 0 ) break;
            ss>>s>>d;
            if(s==d) { cout<<s<<" "<<d<<" 0\n"; continue; }
            path = bfs(s,d, g);
            cout<<s<<" "<<d<<" "<<path<<"\n";
            //cout<<g[s]<<"\n";
        }
    }
    return 0;
}
