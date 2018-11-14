#include<iostream>
using namespace std;
int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    int rem = b - (((a%b)*(10%b))%b);
    if( rem <=9 || rem==b )
    {
        cout<<a<<rem%b;
        while(--n)
        {
            cout<<0;
        }
    }
    else cout<<-1;
    return 0;
}
