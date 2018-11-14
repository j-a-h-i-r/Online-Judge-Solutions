#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    stringstream ss;
    string inp, key, value;
    char baad;
    while(t--)
    {
        getline(cin, inp);
        int ln = inp.length();
        if(ln>2) inp = inp.substr(1,ln-1);
        ss.clear(); ss.str("");
        ss<<inp;
        while( ss>>inp )
    }
}
