#include<iostream>
using namespace std;

int fact(int n)
{
    int i, sum = 1;

    for(i = 1; i<=n; i++)
    {
        sum = sum * i;
    }
    return sum;
}

int main()
{
    int n, r;
    cin>>n>>r;

    cout<<"Permutation : " << fact(n)/fact(r) <<endl;
    cout<<"Combination : " << fact(n)/((fact(r)*fact(n-r))) <<endl;
}
