#include<iostream>
using namespace std;

int main()
{
    int n, t;

    cin>>n>>t;

    int tot = 1;

    int f,s;

    cin>>f;

    while(--n)
    {
        cin>>s;

        if( s-f <= t ) tot++;
        else tot = 1;

        f = s;
    }

    cout<<tot<<endl;
}
