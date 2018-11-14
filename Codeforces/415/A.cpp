#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    int a[n+1];
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    int i;
    for (i=n; ; i++) {
        if (round( double(sum)/double(i) ) == k ) break;
        sum += k;
    }

    cout<<i-n<<endl;

    return 0;
}
