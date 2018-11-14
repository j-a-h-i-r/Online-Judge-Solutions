#include<iostream>
#include<cmath>
#include<cstdio>
#include<queue>
#include<vector>
#include<sstream>
using namespace std;

int l2n(char c) { return (c-'A'); }

double mxVal = -1;
int mxP;

void bfs(int s, vector<int> g[], vector<double> value) {
    double val = value[s], tmp;
    int dis[26];
    int p = s;
    queue<int> q;
    bool vis[26];
    for(int i=0; i<26; i++) vis[i] = false;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            //cout<< "v = "<< v <<endl;
            if(vis[v]==false) {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                //cout<<dis[v]<<endl;
                q.push(v);
            }
        }
    }
    //cout<<char(s+'A')<<endl;
    for(int i=0; i<26; i++) {
        //if(vis[i]) cout<<char(i+'A')<< " "<<dis[i]<<endl;
        if(vis[i]) {
            val = value[i]*pow(0.95, dis[i]);
            //cout<<char(i+'A')<< " "<<val<<endl;
            if(val > mxVal) {
                mxVal = val;
                mxP = i;
            }
            else if(val==mxVal && i<mxP) mxP = i;
        }
    }
    //cout<<endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    while(cin>>n)
    {
        mxVal = -1.0; mxP = 27;

        getchar();
        //cout<< "n = " << n<<endl;
        vector<int> p[26];
        vector<double> value(26);
        vector<int> src;
        string inp, conn;
        char planet;
        double val;
        int u, v;
        stringstream ss;

        for(int i=0; i<n; i++) {
            getline(cin, inp);
            //cout<<inp;
            ss.clear();
            ss.str("");
            ss<<inp;
            ss >> planet>> val >>conn;
            u = l2n(planet);
            //cout<<planet<<" - "<<val<<" - "<<conn<<endl;
            value[u] = val;
            for(int j=0; j<conn.length(); j++ ) {
                if(conn[j]=='*') {
                    src.push_back( u );
                    continue;
                }
                v = l2n(conn[j]);
                p[u].push_back(v);
                //p[v].push_back(u);
                //cout<< "sz "<<p[u].size()<<endl;
            }
        }
        vector<int>::iterator it;
        for(it=src.begin(); it!=src.end(); ++it) {
            bfs( *it, p, value );
        }
        cout<<"Import from "<<char(mxP+'A')<<"\n";
    }
    return 0;
}
