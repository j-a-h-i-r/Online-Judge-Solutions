#include<iostream>
using namespace std;
int main()
{
    int t,cs=0;
    cin>>t;
    while(t--)
    {
        int n, l, sum=0;
        cin>>n>>l;
        bool pos = true;
        int num[n], lim[n];
        for(int i=0; i<n; i++) {
            cin>>num[i];
            sum += num[i];
        }
        for(int i=0; i<n; i++) {
            cin>>lim[i];
            if(lim[i]<num[i]) pos = false;
        }
        if(sum>l) pos=false;

        cout<<"Case "<<++cs<<": ";
        pos? cout<<"Yes\n": cout<<"No\n";
    }
    return 0;
}
