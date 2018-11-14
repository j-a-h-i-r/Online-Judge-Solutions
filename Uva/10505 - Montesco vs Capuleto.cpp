#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

int bfs(vector<int> g[], int n)
{
    int col[250], mx=0, one, zero;
    for(int i=0; i<250; i++) col[i] = -1;
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        if(col[i]==-1)
        {
            bool flag = true;
            one = 0;
            zero = 0;
            q.push(i);
            col[i] = 1;
            one++;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int j=0; j<g[u].size(); j++)
                {
                    int v = g[u][j];
                    if(col[v]==-1)
                    {
                        (col[u]==1)?col[v]=0: col[v]=1;
                        (col[u]==1)?zero++: one++;
                        q.push(v);
                    }
                    else if(col[u]==col[v] )
                    {
                        //cout<<u<<" "<<v<<endl;
                        flag = false;
                    }
                }
            }
            //cout<<flag<<" "<<one<<" "<<zero<<endl;
            if(flag)mx += max(one, zero);
        }
    }

    return mx;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> g[250];
        int p;
        for(int i=1; i<=n; i++)
        {
            cin>>p;
            int x;
            while(p--)
            {
                cin>>x;
                //cout<<x;
                if(x>=1 && x<=n) {
                    g[i].push_back(x);
                    g[x].push_back(i);
                }

            }
        }
        int ans = bfs(g, n);
        cout<<ans<<"\n";
    }
    return 0;
}
