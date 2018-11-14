#include<iostream>
using namespace std;

long long pow(int x, int n) {
    if(n==0) return 1;
    long long p = pow(x, n/2);
    if(n%2==0) {
        return p*p;
    }
    else return x*p*p;
}

int main()
{
    int n,x;
    cin>>n>>x;
    cout<<pow(n,x);
}
