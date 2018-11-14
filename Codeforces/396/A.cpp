#include<iostream>
using namespace std;
int main()
{
    string a, b;
    cin>>a>>b;
    int c=a.length();
    int d=b.length();

    if(a==b) cout<<-1;
    else cout<<max(c,d);
}
