#include<iostream>
#include<cstdio>
#include<sstream>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    bool line = false;
    int t, cs = 0;
    cin>>t;
    getchar();
    getchar();
    while(t--)
    {
        string inp, ans = "";
        stringstream ss;

        if(line) cout<<"\n"; line = true;
        cout<<"Case #"<<++cs<<":\n";

        while( getline(cin, inp) )
        {
            if( inp.length() == 0 ) break;

            int p = 0;
            ans = "";
            ss.clear();
            ss.str("");
            ss<<inp;
            while(ss>>inp)
            {
                if( p < inp.length() ) ans += inp[p++];
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
