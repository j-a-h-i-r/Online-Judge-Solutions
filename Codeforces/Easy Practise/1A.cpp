#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,a;
    cin>>m>>n>>a;
    long long int x = ceil((double)m/a)*ceil((double)n/a);
    cout<<x<<endl;
    return 0;
}
