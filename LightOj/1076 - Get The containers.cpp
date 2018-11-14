#include<iostream>
#include<cstdio>
using namespace std;

int findCap(int ara[], int k, int n)
{
    int taken=0, sum=0;
    for(int i=0; i<n; i++)
    {
        if(ara[i]>k) return -1;

        if(sum+ara[i] <= k)
        {
            sum+=ara[i];
        }
        else {
            taken++;
            sum = ara[i];
        }
    }
    if(sum) taken++;
    return taken;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t, cs=0;
    int m,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int ara[n], mc = -1;
        for(int i=0; i<n; i++) {
            cin>>ara[i];
            mc = max(mc, ara[i]);
        }

        if(n <= m ) {
            cout<<"Case "<<++cs<<": ";
            cout<<mc<<"\n";
            continue;
        }

        int l=1, u=1e9;
        int ans = 1e9;

        while(l < u)
        {
            int mid = (u+l)/2;
            //cout<<l<<" "<<u<<" ";

            int cap = findCap(ara, mid, n);
            //cout<<mid<<" "<<cap<<endl;

            if(cap==-1 || cap>m) l=mid+1;
            else if(cap<=m)
            {
                ans = min(ans, mid);
                u = mid;
            }
        }
        cout<<"Case "<<++cs<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
