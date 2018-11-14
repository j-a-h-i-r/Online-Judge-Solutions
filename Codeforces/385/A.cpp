#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l = s.length();
    int pre = 0;
    int st = 0;
    int d=1;
    int dp=0;
    int pred;
    bool poss = true;

    for(int i=1; i<l; i++)
    {
        if( s[i]==s[0] )
        {
            if(dp==0) {
                pred= i-dp;
                //cout<<pred<<" "<<i<<" "<<dp<<"\n";
                dp=i;
            }
            else {
                if( pred == (i-dp) ) {
                    dp = i;
                }
                else { poss= false; break; }
            }
        }
    }
    //cout<<poss<<" "<<pred<<" ";
    if(!poss || dp==0 || (l%pred)!=0 ) cout<<l;
    else {
        for(int i=0; i<l; i++)
        {
            if( s[i]==s[i%pred] ) {

            }
            else poss = false;
        }
        if(poss) cout<<pred;
        else cout<<l;
    }
    return 0;
}
