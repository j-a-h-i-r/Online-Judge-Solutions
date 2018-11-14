#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    long l,r;

    cin>>n>>l>>r;

    long a[n], val;
    pair<long, int> c[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>val;
        c[i] = make_pair(val, i);
    }
    sort(c, c+n);
    long ct = r - a[c[0].second-1];

    cout<<ct<<endl;

    long b[n];
    long t;

    for(int i=0; i<n; i++)
    {
        t = ct
    }



    return 0;
}
