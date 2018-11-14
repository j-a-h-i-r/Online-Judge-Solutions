#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    int l, d;

    l = ceil( double(k)/double(2*m) );
    k = k%(2*m);
    d = ceil( double(k)/double(2) );

    if(d==0) d = m;

    cout<<l<<" "<<d<<" ";
    (k%2==0)? cout<<"R":cout<<"L";

    return 0;
}
