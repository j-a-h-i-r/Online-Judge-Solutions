#include<iostream>
using namespace std;
int main()
{
    long long n, k;
    cin>>n>>k;

    long long dip, cer, non;

    dip = n/(2*(1+k));
    cer = dip * k;
    non = n - ( dip + cer );

    cout<<dip<<" "<<cer<<" "<<non<<endl;
}
