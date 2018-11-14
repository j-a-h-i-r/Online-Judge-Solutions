#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        vector< int > v;
        int n;
        int k,p;
        cin>>n;
        while(n--)
        {
            cin>>k>>p;
            while(k--)v.push_back(p);
        }
        sort(v.begin(), v.end());

        int l = v.size();
        int ans = 0;
        for(int i=0; i<l; i++)
        {
            ans = max(ans, v[i]*(l-i) );
        }
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
