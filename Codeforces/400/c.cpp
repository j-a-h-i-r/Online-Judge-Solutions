#include<iostream>
#include<map>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r", stdin);

    int n;
    cin>>n;
    long long csum[n+1], a, k;
    cin>>k;
    csum[0] = 0;
    map<long long, int> mc;
    for(int i=1; i<=n; i++) {
        cin>>a;
        csum[i] = csum[i-1] + a;
        mc[csum[i]]++;
    }

    map<long long, bool> mp;

    if(k==1) {
        mp[1] = true;
    }
    else if(k==-1) {
        mp[1] = true; mp[-1] = true;
    }
    else {
        long long p = 1;
        for(int i=0; ; i++) {
            if(abs(p)>=1e15) break;
            else  mp[p] = true;
            p = p*k;
        }
    }

    long long cnt = 0;
    map<long long, bool>::iterator it;
    for(int i=n; i>0; i--) {
        for(it=mp.begin(); it!=mp.end(); ++it) {
            if(csum[i]==it->first) {
                cnt += 1 + mc[0] ;
                //cout<<csum[i]<<endl;
            }
            else if( mc.find( csum[i] - it->first ) != mc.end() ) {
                //cout<<it->first<<endl;
                cnt += mc[ csum[i] - it->first ];
            }
        }
        mc[ csum[i] ]--;
    }

    cout<<cnt<<"\n";

    return 0;
}
