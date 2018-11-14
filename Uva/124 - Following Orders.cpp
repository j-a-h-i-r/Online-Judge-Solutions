#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

char ch[30], pos[30];
int n;
vector<char> before[150];
int taken[150];

void show_all(int id)
{
    if(id==n) {
        for(int i=0; i<n; i++) {
            cout<<pos[i];
        }
        cout<<"\n";
        return;
    }
    else {
        for(int i=0; i<n; i++) {
            if( taken[ch[i]]==0 ) {
                taken[ ch[i] ] = 1; // already taken
                //cout<<ch[i]<<" = ";
                for(int j=0; j<before[ch[i]].size(); j++) {
                    if(taken[before[ch[i]][j]] ==0) {
                        taken[before[ch[i]][j]] = 2; // this depends on another value
                                                     // can't be taken
                    }
                    //cout<<before[ch[i]][j];
                }
               // cout<<endl;

                pos[id] = ch[i];
                show_all(id+1);

                taken[ ch[i] ] = false;
                for(int j=0; j<before[ch[i]].size(); j++) {
                    if(taken[before[ch[i]][j]] == 2) {
                        taken[before[ch[i]][j]] = 0;
                    }
                }

            }
        }
    }
}

using namespace std;
int main( )
{
    //freopen("in.txt","r",stdin);
    bool line = false;

    stringstream ss;
    string inp;
    char c, d;
    int i;
    while( getline(cin,inp) )
    {
        if(line) cout<<"\n"; line = true;

        for(int i=0; i<150; i++) {
            before[i].clear();
            taken[i] = 0;
        }

        i=0;

        ss.clear();
        ss.str("");
        ss<<inp;
        while( ss>>c ) {
            ch[i++] = c;
            //cout<<c<<" ";
        }
        //cout<<endl;
        sort(ch, ch+i);

        n = i;

        ss.clear();
        ss.str("");
        getline(cin, inp);
        ss<<inp;

        while(ss>>c>>d) {
            //cout<<c<<" "<<d<<endl;
            before[d].push_back(c);
        }
        //cout<<endl;

        show_all( 0 );
    }
    return 0;
}
