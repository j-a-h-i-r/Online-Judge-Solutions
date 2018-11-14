#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int m = (n/2) - 1;

    cout<<m+1<<"\n";

    for(int i=0; i<m; i++) cout<<2<<" ";

    if(n%2==1)
    {
        cout<<3;
    }
    else cout<<2;

    return 0;
}
