#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        set<int> jackCD;
        int x;
        while(n--) {
            cin>>x;
            jackCD.insert(x);
        }
        int sell = 0;
        while(m--)
        {
            cin>>x;
            if( jackCD.find(x)!=jackCD.end() ) sell++;
        }
        cout<<sell<<"\n";
    }
    return 0;
}
