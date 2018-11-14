#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct B
{
    long long p, c;
    B(long long x, long long y) {
        p = x; c = y;
    }
    friend bool operator<(B &x, B &y) {
        return (min(2*x.p, x.c) - min(x.c, x.p)) > (min(2*y.p, y.c)-min(y.c, y.p));
    }
};

int main()
{
    long long n, f, x, y;
    cin>>n>>f;
    vector<B> st;
    long long sum = 0;
    for (int i=0; i<n; i++) {
        cin>>x>>y;
        st.push_back(B(x, y));
        sum += min(x, y);

    }
    vector<long long> dif;
    for (int i=0; i<n; i++) {
        dif.push_back( min(2*st[i].p, st[i].c ) - min(st[i].p, st[i].c) );
    }
    //sort(st.begin(), st.end());
    sort(dif.begin(), dif.end(), greater<long long>());

    for (int i=0; i<f; i++) {
        //cout<<st[i].p<<endl;

        sum += dif[i];
    }
    cout<<sum<<endl;
}
