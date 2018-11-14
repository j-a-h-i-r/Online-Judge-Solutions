#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<cstdio>

using namespace std;

class comp
{
    public:
    bool operator() (pair<int,long> a, pair<int, long> b)
    {
        return a.second > b.second;
    }
};


int main()
{
    //freopen("in.txt", "r", stdin);

    int n,m,k;
    cin>>n>>m>>k;

    vector< priority_queue<pair<int,long>, vector<pair<int,long> >, comp > > vec(n+1);

    while(m--)
    {
        int u,v;
        long l;
        cin>>u>>v>>l;

        //cout<< u << v << l <<endl;

        vec[u].push( make_pair(v,l) );
        vec[v].push( make_pair(u,l) );
    }

    if(k==0)
    {
        cout<<-1<<endl;
        return 0;
    }

    vector<int> ware(k+1);
    map<long, bool> mp;

    while(k--)
    {
        int w;
        cin>>w;
        //cout<<w<<endl;

        ware.push_back(w);
        mp[w] = true;
    }

    long ans = 1e9 + 5;
    for(int i=1; i<=n; ++i)
    {

        while( vec[i].empty()  == false )
        {
            int node = vec[i].top().first;
            long len = vec[i].top().second;

            if( mp.find(node) != mp.end() )
            {
                // not a warehouse
                ans = min(ans, len);
                break;
            }
            else vec[i].pop();

            //cout<<"debug" <<endl;
        }
    }

    if( ans == 1e9 + 5 ) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}
