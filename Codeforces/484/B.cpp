#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Foo
{
public:
    long seat;
    int row;
    Foo() {}
    Foo(long a, long b) {seat=a; row=b;}
};

struct Compare
{
    bool operator() (Foo a , Foo b)
    {
        return a.seat < b.seat;
    }
};
bool cmp(Foo a, Foo b)
{
    return a.seat < b.seat;
}

int main()
{
    int n;
    cin>>n;
    Foo width[n+1];
    long w;
    int r;
    for(int i=1; i<=n; i++) {
        cin>>w;
        width[i] = Foo(w, i);
    }
    sort(width+1, width+n+1, cmp);
    int x=1, y=n;

//    set<long>in, out;
    priority_queue<Foo, vector<Foo>, Compare> pq;
    string s;
    cin>>s;
    int len = s.length();
    //in.push_back(width[1]);
    for(int i=0; i<len; i++) {
        if(s[i]=='0') {
            // in
            cout<<width[x].row<<" ";
            pq.push(Foo(width[x].seat, width[x].row));
            //cout<<"-"<<pq.top().row<<"- ";
            x++;
        }
        else {
            Foo f = pq.top(); pq.pop();
            cout<<f.row<<" ";
        }
    }
    return 0;
}
