#include<iostream>
#include<cstdio>
using namespace std;

bool pointIsFine(int x, int p)
{
    int i = (p / 50) % 475;
    for (int j=1; j<=25; j++) {
        i = ( (i * 96 + 42) % 475);
        //cout << i<<" ";
        if (26 + i==x) return true;
    }
    //cout<<endl;
    return false;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int p, x, y, t1, t2;
    bool nohack = false;
    cin>>p>>x>>y;
    int i;
    for (i=0;  ; i += 50) {
        t1 = x + i;
        bool f1 = pointIsFine(p, t1);
        //cout<< f <<endl;
        if ( f1 && t1 >= y ) break;
    }
    int j;
    if ( x > y ) {
        for (j=0; ; j+=50) {
            t1 = x - j;
            bool f1 = pointIsFine(p, t1);
            //cout<< f <<endl;
            if (t1 < y) break;
            if ( f1 && t1 >= y ) {
                nohack = true;
                break;
            }
        }
    }
    if (nohack) {
        cout<<0;
        return 0;
    }
    int hack = i/100;
    if (i%100 == 0) cout<<hack<<endl;
    else cout<<hack+1;
}
