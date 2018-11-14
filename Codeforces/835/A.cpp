#include<iostream>
#include<algorithm>
using namespace std;

int find_mex(int ara[], int n, int x)
{
    if (n==1) {
        if (ara[0]==0) return 1;
        else return 0;
    }

    for(int i=0; i<n; i++) {
        if (ara[i] > i) return i;
    }
    return ara[n-1] + 1;
}

int main()
{
    int n, x;
    cin>>n>>x;
    int ara[n];
    for (int i=0; i<n; i++) {
        cin>>ara[i];
    }
    sort(ara, ara+n);
    for (int i=0; i<n; i++) {
        cout<<ara[i]<<" ";
    }
    cout<<endl;

    int mex = find_mex(ara, n, x);
    if (mex < x) {
        int idx = 0;
        while( ara[idx] < mex ) idx++;

        int cnt = 0;
        while(ara[idx]<x) cnt++, idx++;

        cout<<(x-mex) - cnt<<endl;
    }
    else if (mex > x) {
        cout<<1<<endl;
    }
    else cout<<0<<endl;
}
