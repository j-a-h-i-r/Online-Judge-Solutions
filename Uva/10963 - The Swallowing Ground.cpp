#include<iostream>
using namespace std;
int main()
{
    bool line = false;
    int t;
    cin>>t;
    while(t--)
    {
        bool repair = true;
        int n;
        cin>>n;
        int up[n];
        int down[n];
        for(int i=0; i<n; i++)
        {
            cin>>up[i]>>down[i];
        }
        for(int i=1; i<n; i++)
        {
            if( up[i]-down[i] != up[i-1]-down[i-1] ) repair = false;
        }

        if(line) cout<<"\n"; line = true;

        if(repair) cout<<"yes\n";
        else cout<<"no\n";
    }
}
