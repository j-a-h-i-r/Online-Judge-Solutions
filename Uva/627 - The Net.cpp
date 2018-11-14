#include<iostream>
#include<queue>
#include<stack>
#include<sstream>
#include<cstdio>
using namespace std;

void bfs(int sx,int sy, vector<int> *g)
{
    bool vis[305];
    int path[305];
    for(int i=0; i<305; i++) vis[i]=false;
    queue<int> q;
    vis[sx] = true;
    q.push(sx);
    path[sx] = -1; path[sy] = -1;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        //cout<<"u "<<u<<"\n";
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            //cout<<v<<" ";
            if( !vis[v] )
            {
                vis[v]=true;
                q.push(v);
                path[v]=u;
            }
            if(v==sy)
            {
                //cout<<u<<"\n";
                // found it
                q = queue<int>();
                break;
            }
        }
    }
    //cout<<endl;
    //cout<<path[6]<<path[3]<<path[1]<<"\n";
    if( path[sy] == -1 )
    {
        cout<<"connection impossible\n";
        return;
    }
    stack<int> st;
    while(path[sy]!=-1)
    {
        st.push(sy);
        sy=path[sy];
    }
    cout<<sx;
    while(!st.empty())
    {
        cout<<" "<<st.top();
        st.pop();
    }
    cout<<"\n";
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    stringstream ss;
    string inp;
    int n;
    while( scanf("%d",&n) != EOF )
    {
        getchar();
        vector<int> g[305];
        while(n--)
        {
            getline(cin, inp);
            ss.clear();
            ss.str("");
            ss<<inp;
            //cout<<ss.str()<<"\n";
            int id;
            ss>>id;
            //cout<<"id "<<id<<"\n";
            char _;
            ss>>_;
            //cout<<ss.str();
            //cout<<"ch "<<_<<"\n";
            int to;
            while(ss>>to)
            {
                //cout<<to<<" ";
                g[id].push_back(to);
                //g[to].push_back(id);
                ss>>_;
            }
            //cout<<"\n";
        }
        int m;
        cin>>m;
        cout<<"-----\n";
        while(m--)
        {
            int from, to;
            cin>>from>>to;
            //cout<<from<<" "<<to<<"\n";
            bfs( from,to, g );
        }
    }
    return 0;
}
