#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a[101];
    int s, l, n;

    cin>>n;
    for(int j=0; j<n; j++) {
        int m;
        cin>>m;

        if(m==1) s=j+1;
        if(m==n) l = j+1;
    }

    int d = min(s, l) - 1;
    int k = n - max(s, l);

    int dis = max(s,l) - min(s,l) + max(d,k);

    cout<<dis<<endl;
}
