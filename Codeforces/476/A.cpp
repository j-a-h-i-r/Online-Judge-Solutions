#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double k, n, s, p;
    cin>>k>>n>>s>>p;

    double t = ceil(n/s);
    double sheets = t * k;
    double ans = ceil(sheets / p);

    cout<<int(ans);
}
