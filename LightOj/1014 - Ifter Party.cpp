#include<iostream>
#include<stack>
#include<cstdio>
#include<queue>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, cs=0;
    cin>>t;
    long long int p, l, q, eaten;
    while(t--) {
        cin>>p>>l;
        eaten = p-l;
        stack<long int> st;
        queue<long int> qu;

        for (long long int c=1; c*c <= eaten; c++) {
            //if (c*c < eaten) cout<<c<<endl;
            q = eaten/c;
            if (q<=l) break;
            if (eaten%c==0) {
                st.push(q);
                if ( c > l && q!=c ) qu.push(c);
            }
        }

        cout<<"Case "<<++cs<<":";

        if (st.empty()==true) {
            cout<<" impossible\n";
        }
        else {
            while(!qu.empty()) {
                cout<<" "<<qu.front();
                qu.pop();
            }
            while(!st.empty()) {
                cout<<" "<<st.top();
                st.pop();
            }
            cout<<"\n";
        }
    }
    return 0;
}
