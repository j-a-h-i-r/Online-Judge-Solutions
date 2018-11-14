#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int ara[n], sum = 0;
        for(int i=0; i<n; i++) {
            cin>>ara[i];
            sum += ara[i];
        }
        bool poss = true;
        if(sum%4==0) {
            int s = sum/4, ts = 0, tot = 0;
            for(int i=0; i<n; i++) {
                if( ts+ara[i] <= s ) {
                    ts += ara[i];
                    ara[i] = -1;
                }
                if(ts==s) { tot++; break; }
            }
            //cout<<"1 = "<<ts<<tot<<endl;
            ts = 0;
            for(int i=0; i<n; i++) {
                if(  ara[i]!=-1 && ts+ara[i] <= s ) {
                    ts += ara[i];
                    ara[i] = -1;
                }
                if(ts==s) { tot++; break; }
            }
            //cout<<"2 = "<<ts<<endl;
            ts = 0;
            for(int i=0; i<n; i++) {
                if(  ara[i]!=-1 && ts+ara[i] <= s ) {
                    ts += ara[i];
                    ara[i] = -1;
                }
                if(ts==s) { tot++; break; }
            }
            //cout<<"3 = "<<ts<<endl;
            ts = 0;
            for(int i=0; i<n; i++) {
                if(  ara[i]!=-1 && ts+ara[i] <= s ) {
                    ts += ara[i];
                    ara[i] = -1;
                }
                if(ts==s) { tot++; break; }
            }
            //cout<<"4 = "<<ts<<endl;
            if(tot == 4) cout<<"yes\n";
            else cout<<"no\n";
        }
        else cout<<"no\n";
    }
    return 0;
}
