#include<iostream>
using namespace std;

int main()
{
    int v,s1,s2,t1,t2;
    cin>>v>>s1>>s2>>t1>>t2;

    int first = v*s1 + 2*t1;
    int second = v*s2 + 2*t2;

    if (first==second) cout<<"Friendship";
    else if (first < second) cout<<"First";
    else cout<<"Second";
}
