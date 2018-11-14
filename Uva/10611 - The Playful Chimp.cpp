#include<iostream>
#include<cstdio>
using namespace std;

int lowerBound(long a[], int x, int n)
{
    int st=0, en=n-1, mid, ans=-1;
    while(st<=en)
    {
        int mid=(st+en)/2;
        if(a[mid]==x)
        {
            ans=mid;
            en = en-1;
        }
        else if(a[mid]>x) en = mid-1;
        else st = mid+1;
    }
    return (st==0)? -1: a[st-1];
}
int upperBound(long a[], int x, int n)
{
    int st=0, en=n-1, mid, ans=-1;
    while(st<=en)
    {
        int mid=(st+en)/2;
        if(a[mid]==x) {
            ans=mid;
            st=st+1;
        }
        else if(a[mid]>x) en=mid-1;
        else st=mid+1;
    }
    return (en==n-1)? -1: a[en+1];
}

int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    cin>>n;
    long int ara[n+1];
    for(int i=0; i<n; i++) {
        cin>>ara[i];
    }
    int q;
    long h;
    cin>>q;
    for(int i=0; i<q; i++) {
        cin>>h;
        int lb = lowerBound(ara, h, n);
        int ub = upperBound(ara, h, n);

        (lb==-1)?cout<<"X ":cout<<lb<<" ";
        (ub==-1)?cout<<"X\n":cout<<ub<<"\n";
    }
    return 0;
}
