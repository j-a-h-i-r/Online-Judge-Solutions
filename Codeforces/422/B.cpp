#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n, m;
    int cnt=0, mincnt = 99999;
    string s, t;
    cin>>n>>m;
    cin>>s>>t;
    queue<int> fq;

    for(int i=0; i<=m-n; i++)
    {
        cnt = 0;
        queue<int> q;
        for (int j=0; j<n; j++) {
            if ( t[i+j] != s[j] ) {
                cnt++;
                q.push( j+1 );
            }
        }
        if (cnt < mincnt) {
            mincnt = cnt;
            fq = q;
        }
    }
    cout<<mincnt<<"\n";
    while(!fq.empty()) {
        cout<<fq.front()<<" ";
        fq.pop();
    }

    return 0;
}
