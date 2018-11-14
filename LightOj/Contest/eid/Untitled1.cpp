#include<iostream>
using namespace std;

int sum(int a, int b)
{
    int s = a+b;
    return s;
}

int main()
{
    int x, y;
    cin>>x>>y;

    int jogFol = sum(x, y);

    cout<<jogFol;
}
