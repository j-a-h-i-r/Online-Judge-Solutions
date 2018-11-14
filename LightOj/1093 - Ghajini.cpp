#include<cstdio>
#include<deque>
#include<cmath>
using namespace std;

long max_in_range(long ara[], int n, int m)
{
    long mx = -1;
    deque<pair<long int,int> > dqmin, dqmax;
    for (int i=0; i<n; i++) {
        while( dqmax.empty()==false && dqmax.front().first <= ara[i] ) {
            dqmax.pop_front();
        }
        dqmax.push_front( make_pair(ara[i], i) );
        while(dqmax.empty()==false && dqmax.back().second <= (i-m)) {
            dqmax.pop_back();
        }

        while( dqmin.empty()==false && dqmin.front().first >= ara[i] ) {
            dqmin.pop_front();
        }
        dqmin.push_front( make_pair(ara[i], i) );
        while(dqmin.empty()==false && dqmin.back().second <= (i-m)) {
            dqmin.pop_back();
        }

        if (i>=m-1) {
            long diff = abs(dqmax.back().first-dqmin.back().first);
            mx = max(mx, diff);
        }
    }
    return mx;
}

int main()
{
    int t;
    scanf("%d", &t);
    int n, d;
    for (int i=0; i<t; i++) {
        scanf("%d %d", &n, &d);
        long ara[n+1];
        for (int i=0; i<n; i++) {
            scanf("%ld", &ara[i]);
        }

        long ans = max_in_range(ara, n, d);

        printf("Case %d: %ld\n", i+1, ans);
    }
    return 0;
}
