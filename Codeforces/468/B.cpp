#include<iostream>
using namespace std;

int power(int a, int b) {
    int ans = 1;
    for (int i=1; i<=b; ++i) {
        ans = ans * a;
    }
    return ans;
}

int main()
{
    int n, a, b, c, d;
    cin>>n>>c>>d;
    a = min(c, d);
    b = max(c, d);
    int ans;

    for (int i=1; i; ++i) {
        if (a+1 == b && a%2==1) {
            ans = i;
            break;
        }
        a = (a+1)/2;
        b = (b+1)/2;
    }

    if ( power(2, ans) == n ) {
        cout<<"Final!";
    }
    else cout<<ans;
}
