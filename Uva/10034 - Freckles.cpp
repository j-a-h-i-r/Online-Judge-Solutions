#include<iostream>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;

double x[101], y[101];

struct node{
    double d;
    int in;
    node(double a, int b) {
        d = a; in = b;
    }
    friend bool operator<(node a, node b)
    {
        return a.d>b.d;
    }
};

double dist(int i, int j)
{
    double a = x[i]-x[j];
    double b = y[i]-y[j];
    return sqrt( a*a + b*b );
}

double bfs(int n)
{
    priority_queue<node> pq;
    pq.push( node(0.0, 0) );
    bool vis[n+1];
    double dis = 0.0, mn=999999, tm;
    int visited = 0, cur = 0, mni;
    for(int i=0; i<=n; i++) vis[i] = false;
    vis[0] = true;

    while( visited < n )
    {
        node u = pq.top(); pq.pop();
        dis += u.d;
        vis[u.in] = true;
        visited++;

        for(int i=0; i<n; i++) {
            if(i==u.in || vis[i] ) continue;
            tm = dist( i, u.in );
            pq.push(node(tm, i));
        }

        while(!pq.empty()) {
            if(vis[pq.top().in]) pq.pop();
            else break;
        }
    }
    return dis;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t; bool line = false;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        if(line) printf("\n"); line = true;

        double ans = bfs(n);
        printf("%.2f\n", ans);

    }
    return 0;
}
