#include<iostream>
using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
    while( b!=0 )
    {
        ll t = b;
        b = a%b;
        a = t;
    }
    return a;
}


ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;

    //cout<<gcd(a,b);
    //cout<< " " << lcm(a,b)<<endl;

    ll r = (n/a), blue = (n/b), both = n/lcm(a,b);

    //cout<<r<< " "<< blue<< " "<< both<<" "<<lcm(a,b)<<endl;

    cout<<(r-both)*p + (blue-both)*q + max(p,q)*both<< endl;
}
