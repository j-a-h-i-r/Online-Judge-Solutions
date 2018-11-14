#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l = s.length()-1;

    while(l>=0) {
        if (s[l]=='0') {
            cnt++;
            pre = 0;
        }
        else {
            if ( (pre + s[l]-'0')%3 ==0 ) {
                ++cnt;
                pre = 0;
            }
            else {
                pre =
            }
        }
    }
}
