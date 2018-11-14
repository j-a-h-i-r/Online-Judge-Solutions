#include<iostream>
using namespace std;
int main()
{
    unsigned long long n, k;
    while(cin>>n>>k)
    {
        if(n==0 && k==0) break;

        unsigned long long m = min(k, n-k);

        unsigned long long ans = 1;

        for(unsigned long long i=1; i<=m; i++)
        {
            ans = ans*(n-m+i)/i;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
