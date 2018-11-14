#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    long a[n+1];
    int p[n+1];
    long t;
    vector<long> v[32];
    int pos;

    int one = 0, two=0;

    for (int i=0; i<n; i++) {
        scanf("%ld", &a[i]);
        //cout<<a[i]<< " a[i] ";
        if (a[i]==1) one++;
        else if (a[i]==2) two++;

        t = a[i];
        pos = 0;
        while(t>0) {
            if (t & 1 == 1) {
                v[pos].push_back(a[i]);
                //cout<<pos<<endl;
                p[i] = pos;
                break;
            }

            ++pos;
            t = t>>1;
        }

        pos = 0;
    }


    int cnt = 0;
    long s;

    for (int i=0; i<n; i++) {

        for (int j =0 ; j<v[ p[i] ].size(); j++) {
            //cout<<v[p[i]][j]<<endl;;
            s = a[i] + v[ p[i] ][j];
            //cout<<" s="<<(s&(s-1))<<endl;;
            if ( (s & (s-1)) == 0) {
                //cout<<"fond";
                ++cnt;
                break;
            }
        }
    }

    printf("%d\n", n - cnt);
}
