#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n, b;
    cin>>n>>b;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];
    int o = 0, e = 0;
    if (a[0]%2==0) e++;
    else o++;

    vector<int> v;

    for (int i=1; i<n-1; i++) {
        if (a[i]%2==0) e++;
        else o++;

        if (o == e) {
            v.push_back(abs(a[i]-a[i+1]));
        }
    }

    sort(v.begin(), v.end());

    int cnt = 0, csum = 0;
    for (int i=0; i<v.size(); i++) {
        csum += v[i];
        if (csum <= b) cnt++;
        else break;
    }

    cout<<cnt;

    return 0;
}
