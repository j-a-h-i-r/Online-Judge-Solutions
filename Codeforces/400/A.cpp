#include<iostream>
using namespace std;
int main()
{
    string a, b;
    string ara[2];
    cin>>a>>b;
    ara[0] = a; ara[1] = b;
    cout<<a<<" "<<b<<"\n";
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a>>b;
        if(a==ara[0]) {
            cout<<b<<" "<<ara[1]<<"\n";
            ara[0] = b;
        }
        else if(a==ara[1]) {
            cout<<b<<" "<<ara[0]<<"\n";
            ara[1] = b;
        }
        else if(b==ara[0]) {
            cout<<a<<" "<<ara[1]<<"\n";
            ara[0] = a;
        }
        else if(b==ara[1]) {
            cout<<b<<" "<<ara[0]<<"\n";
            ara[1] = a;
        }
    }
    return 0;
}
