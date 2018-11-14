#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n, x;
    cin>>n>>x;
    bool taken[1000010];
    int val[n];
    int cnt[1000010];

    for(int i=0; i<1000010; i++)
    {
        cnt[i]=0;
        taken[i] = false;
    }
    int mx = -1;
    for(int i=0; i<n; i++)
    {
        cin>>val[i];
        cnt[ val[i] ]++;
        if(val[i]>mx) mx = val[i];
    }
    long ans = 0;
    for(int i=0; i<n; i++)
    {
        int y = val[i] ^ x;
        if( y<=mx && taken[ y ]==false )
        {
            ans+=cnt[y];
            taken[val[i]] = true;
            if( val[i]==y ) ans--;
        }
    }
    cout<<ans;
}
