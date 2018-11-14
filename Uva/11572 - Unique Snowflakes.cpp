#include<iostream>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    while(t--)
    {
        set<long> st;
        int n;
        cin>>n;
        long x;
        while(n--)
        {
            cin>>x;
            st.insert(x);
        }
        cout<<st.size()<<"\n";
    }
    return 0;
}
