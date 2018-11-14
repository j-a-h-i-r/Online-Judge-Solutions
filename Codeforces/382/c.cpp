#include<iostream>
using namespace std;
int main()
{
    long long ara[200];
    ara[0] = 1;
    ara[1] = 1;

    int i;
    for(i=2; ; i++)
    {
        ara[i] = ara[i-1] + ara[i-2];
        if( ara[i] > 1e18 ) break;
    }

    int lim = i-1;

    long long n;
    cin>>n;

    for(i=0; i<=lim; i++)
    {
        if(ara[i]>n) break;
    }

    cout<<i-2<<"\n";
}
