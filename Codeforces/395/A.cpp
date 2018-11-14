#include<bits/stdc++.h>
using namespace std;

long gcd(long a, long b)
{
    if(b==0) return a;
    a%=b;
    return gcd(b,a);
}

long lcm( long a, long b )
{
    return a*b/gcd(a,b);
}

int main()
{
    long n,m,z;
    cin>>n>>m>>z;

    cout<<z/lcm(n,m);
    return 0;
}
