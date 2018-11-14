#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;

    long int ans = 0;
    int s, d;

    for (int i=0; i<n; ++i) {
        cin>>s>>d;

        if (s>ans) {
            ans = s;
        }
        else {
            //find day greater than ans
            int day = ceil( double(ans-s)/double(d) );

            long int a = s + day*d;
            if (a>ans) ans = a;
            else ans = a+d;
        }
    }
    cout<<ans;

    return 0;
}
