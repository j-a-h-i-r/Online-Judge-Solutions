#include<iostream>
using namespace std;
int main()
{
    int t, cs=0;
    cin>>t;
    while(t--)
    {
        int x;
        bool every = true;
        for(int i=0; i<13; i++)
        {
            cin>>x;
            if(x==0) every = false;
        }
        if(every) cout<<"Set #"<<++cs<<": Yes\n";
        else cout<<"Set #"<<++cs<<": No\n";
    }
    return 0;
}
