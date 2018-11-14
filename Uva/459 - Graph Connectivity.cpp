#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

bool vis[27];

int connected(vector<int> v[], int n)
{
    memset(vis, false, sizeof vis);

    int tot = 0;
    queue<int> q;
    for(int i=0; i<=n; i++)
    {
        //cout<<i<<endl;

        if( vis[i] == false )
        {
            vis[i] = true;
            q.push(i);
            ++tot;
        }
        else continue;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int i=0; i<v[node].size(); i++)
            {
                if(vis[ v[node][i] ] == false )
                {
                    vis[v[node][i] ] = true;
                    q.push( v[node][i] );
                }
            }
        }
    }
    return tot;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin>>t;

    cin.clear();
    getchar();
    getchar();

    while(t--)
    {
        char c;
        cin>>c;
        //cout<<c<<endl;
        getchar();

        char s[5];
        vector<int> v[26];
        while(fgets(s, 4, stdin) )
        {
            if(s[0] == '\n') break;

            //cout<<c << "  "<<  s<<endl;

            int i = s[0]-'A', j = s[1] - 'A';
            //cout<<i << " "<< j<<endl;
            v[i].push_back(j);
            v[j].push_back(i);
        }

        cout<<connected(v, c-'A')<<endl;
        if(t) cout<<endl;

        //cin.clear();
        //cin.ignore(1000, '\n');

    }

    return 0;
}
