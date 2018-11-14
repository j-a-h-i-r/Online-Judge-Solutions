#include<iostream>
using namespace std;
int main()
{
    string st;
    cin>>st;

    //locate the first 1;
    int i=0;
    for(; i<st.length(); i++) {
        if (st[i]=='1') break;
    }
    if (i==st.length()) {
        cout<<"no";
        return 0;
    }
    // count number of 0 after it;
    int count = 0;
    for (; i<st.length(); i++) {
        if (st[i] == '0') count++;
    }

    if (count >= 6) cout<<"yes";
    else cout<<"no";

    return 0;
}
