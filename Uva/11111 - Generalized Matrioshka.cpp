#include<iostream>
#include<stack>
#include<sstream>
#include<cstdio>
using namespace std;

struct start {
    int val;
    int sum;
    start(int _n, int _s)
    {
        val = _n;
        sum = _s;
    }
};

int main()
{
    //freopen("in.txt","r",stdin);

    string inp;
    stringstream ss;
    while(getline(cin,inp))
    {
        bool pos = true;
        stack<start> st;
        ss.clear();
        ss.str("");
        ss<<inp;
        int n;
        while( ss>>n )
        {
            if( n<0 )
            {
                if(!st.empty())
                {
                    st.top().sum += n;
                    if( st.top().sum <= st.top().val ) {
                        pos = false;
                        break;
                    }
                }
                st.push( start(n, 0));
            }
            else {
                if( st.empty() || st.top().val!= -n ) {
                    pos = false;
                    break;
                }
                st.pop();
            }
        }
        if( st.empty() && pos ) cout<<":-) Matrioshka!\n";
        else cout<<":-( Try again.\n";
    }
    return 0;
}
