#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t, cs=0;
    cin>>t;
    while(t--)
    {
        int n, u,v, mx=-1,num;
        cin>>n;
        int ara[n+1];
        bool vis[n+1];
        for(int i=1; i<=n; i++){
            cin>>u>>v;
            ara[u] = v;
            vis[i] = false;
        }
        for(int i=1; i<=n; i++) {
            if(vis[i]) continue;
            int j=ara[i], cnt=0;
            vis[i] = true; vis[j] = true;
            //set<int> st;
            //st.insert(i);
            while( vis[j] == false )
            {
                //st.insert(j);
                j = ara[j];
                vis[j] = true;
            }
            cnt = st.size();
            if(cnt > mx) {
                mx = cnt;
                num = i;
            }
        }
        cout<< "Case "<<++cs<<": ";
        cout<<num<<"\n";
    }
    return 0;
}
