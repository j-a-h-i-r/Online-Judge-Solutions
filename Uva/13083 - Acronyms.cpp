#include<iostream>
#include<sstream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt", "w", stdout );
    stringstream ssa, ssn;
    string author, name, inp;
    while( getline(cin, inp) )
    {
        ssa.clear();
        ssa.str("");
        ssa<<inp;
        getline(cin, inp);
        ssn.clear();
        ssn.str("");
        ssn<<inp;

        vector<char> ath, nm;

        int i=0,j=0;
        while(ssa>>author)
        {
            ath.push_back(author[0]); i++;
        }
        while(ssn>>name) {
            nm.push_back(name[0]);
            j++;
        }

        if(i!=j) {
            cout<<"no\n";
            continue;
        }

        j = min(i,j);

        bool match = true;

        for(i=0; i<j; i++) {
            if( ath[i]!=nm[i] ) match = false;
        }

        if(match) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
