#include<iostream>
using namespace std;
int main()
{
    long long fact[50], i;
    fact[0] = 1;
    for(i=1; ; i++)
    {
        long long n = fact[i-1]*i;
        if( n > 0   ) fact[i] = n;
        else break;
    }
    cout<<i<<endl;
    for(int j=0; j<i; j++) cout<<j<<"\t"<<fact[j]<<endl;
}
