#include<iostream>
using namespace std;

unsigned long long facto(unsigned long long n)
{
    unsigned long long i = 1, f=1;
    while( i<=n ) {
        f = f*i;
        i++;
    }
    return f;
}

int main()
{
    unsigned long long a, b;
    cin>>a>>b;

    cout<<facto( min(a, b) );

    return 0;
}
