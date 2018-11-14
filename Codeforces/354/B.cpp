#include<iostream>
using namespace std;
int main()
{
    int n, t, tot = 0 , i;
    cin>>n>>t;

    for(i=1; i<=n; i++) {
        int d = (i)*(i+1)/2;
        if(d>t) {
            break;
        }
    }
    tot = (i)*(i-1)/2;
    t = t - tot;

    // currently i+1 level e achi

    int p , s = 0;

    //cout<<i<< " "<<t<<endl;

    p = (i/2) + 1;

    if(i%2==0) {
        if(t - p >= 0 ) {
            t = t-p;
            tot = tot+2;

            while( t>0 && p<n) {
            tot = tot + 2;
            t = t-1;
            p++;
    }

        }
    }
    else {
        if(t-p>=0) {
            t = t-p;
            tot++;

            while( t>0 && p<n) {
            tot = tot + 2;
            t = t-1;
            p++;
    }
        }
    }

    cout<<min(tot, (n*(n+1))/2 )<<endl;
    return 0;
}
