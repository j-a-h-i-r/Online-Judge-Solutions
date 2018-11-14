#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin>>c>>d;
    a = min(c, d);
    b = max(c, d);

    int mid = (a+b)/2;

    int d1 = mid-a, d2 = b-mid;


    int ans = (d1*(d1+1))/2 + (d2*(d2+1))/2;
    cout<<ans;
}
