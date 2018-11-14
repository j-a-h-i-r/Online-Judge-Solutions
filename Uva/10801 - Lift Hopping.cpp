#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<cstdio>
#include<climits>
using namespace std;

struct node{
    int t, l, f;
    node(int a,int b, int c){
        t=a; l=b; f=c;
    }
    friend bool operator<(node a, node b) {
        return a.t>b.t;
    }
};

int dij( int n, int lf, int d, int stop[][100], int time[] )
{
    if (d==0) return 0;
    int des[n][100];
    for(int i=0; i<n; i++) {
        for(int j=0; j<100; j++ ) des[i][j] = INT_MAX;
        des[i][0] = 0;
    }
    priority_queue<node> pq;
    pq.push( node(0,lf,0) );
    des[lf][0] = 0;
    while(!pq.empty()) {
        node u = pq.top(); pq.pop();
        //cout<<u.l<<" - "<<u.f<<endl;
        for(int i=u.f+1; i<100; i++) {
            if( stop[u.l][i] != 0 ) {
                // this is next stop;

                if( des[u.l][u.f] + (i-u.f)*time[u.l] < des[u.l][i] ) {
                    //cout<<u.l<< " "<<i<<endl;
                    des[u.l][i] = des[u.l][u.f] + (i-u.f)*time[u.l];
                    pq.push( node( des[u.l][i], u.l, i ) );
                    //cout<<"d "<<des[u.l][i]<<endl;
                    //if( i==d ) return des[u.l][i];
                }
                break;
            }
        }
        for(int i=u.f-1; i>0; i--) {
            if( stop[u.l][i] != 0 ) {
                // this is next stop;
                if( des[u.l][u.f] + (u.f-i)*time[u.l] < des[u.l][i] ) {
                    des[u.l][i] = des[u.l][u.f] + (u.f-i)*time[u.l];
                    pq.push( node( des[u.l][i], u.l, i ) );
                    //cout<<"d "<<des[u.l][i]<<endl;
                    //if( i==d ) return des[u.l][i];
                }
                break;
            }
        }
        // let's see if we can change the lift
        for(int i=0; i<n; i++) {
            if( i!=u.l && stop[i][u.f] == 1  ) {
                stop[i][u.f] = 2;
                des[i][u.f] = min(des[i][u.f], des[u.l][u.f] + 60);
                //cout<<i<<" "<<u.l<<endl;
                pq.push( node(des[u.l][u.f]+60 , i, u.f ));
                //cout<<"d";
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<n; i++) {
        ans = min( ans, des[i][d] );
    }
    return ans;
    //return INT_MAX;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w", stdout);

    int n,k;
    while(cin>>n>>k) {
        int time[n], stop[n][100], u;
        vector<int> g[n];
        string inp;
        stringstream ss;
        for(int i=0; i<n; i++) {
            cin>>time[i];
            for(int j=0; j<100; j++) stop[i][j] = 0;
        }
        getchar();
        for(int i=0; i<n; i++) {
            getline(cin, inp);
            //cout<<"- "<<inp<<" -";
            ss.clear();
            ss.str("");
            ss<<inp;
            while(ss>>u)
            {
                //cout<<u<<endl;
                g[i].push_back(u);
                stop[i][u] = 1;
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            if(stop[i][0]==1) {
                // it stops at 0th floor
                // do a dijkstra
                // and take the min of it;
                ans = min( ans, dij(n, i, k, stop, time) );
            }
        }
        if(ans==INT_MAX) cout<<"IMPOSSIBLE\n";
        else cout<<ans<<"\n";
    }
    return 0;
}

