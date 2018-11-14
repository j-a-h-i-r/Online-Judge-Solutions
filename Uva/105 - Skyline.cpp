#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int skyline[ 10001*2 ];
    for(int i=0; i<10001*2; i++) {
        skyline[i] = -1;
    }

    int l, h, r;
    int s = 1000000, k = -1;
    while (cin>>l>>h>>r) {
        for (int i=l; i<=r-1; i++) {
            skyline[ i*2 ] = max(skyline[ i*2 ], h);
            skyline[i*2+1] = max(skyline[i*2+1], h);
        }
        skyline[ r*2 ] = max(skyline[r*2], h);
        s = min(l, s);
        k = max(r, k);
    }
    /*for(int i=s*2; i<=k*2; i++) printf("%2d ", i);
    cout<<endl;
    for (int i = 2*s; i <= 2*k; i++) {
        //cout<<skyline[i]<<" ";
        printf("%2d ", skyline[i]);
    }
    cout<<endl;*/

    //cout<<"(";
    for(int i=2*s; i<=2*k; i++) {
        if( skyline[i-1] != skyline[i] ) {
            // mismatches
            cout<<i/2<<" ";
            (skyline[i]==-1)? cout<<0:cout<<skyline[i];
            cout<<" ";
        }
    }
    cout<<k<<" 0"<<endl;

    return 0;
}
