#include<iostream>
using namespace std;
int main()
{
    unsigned long long n;
    while(cin>>n)
    {
        if(n==0) break;

        if(n%9==0) cout<< 10*(n/9)-1<<" ";
        cout<<(10*n)/9<<"\n";
    }
    return 0;
}
