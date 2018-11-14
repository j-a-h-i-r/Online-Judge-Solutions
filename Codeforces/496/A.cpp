#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[2000];
    int n;
    cin>>n;
    bool f= false;
    vector<int> v;
    int cnt = 0;
    int x, y = -1;
    for (int i=0; i<n; i++) {
        cin>>x;

        if (x==1) {
            if (f==false) {
                f = true;
            }
            else {
                cnt++;
                v.push_back(y);
            }
        }
        y = x;
    }
    cnt++;
    v.push_back(x);

    cout<<cnt<<endl;
    for (int i=0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
}
