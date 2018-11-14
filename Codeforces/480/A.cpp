#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;

    int dash = 0, dot=0;

    for (int i=0; i<s.length(); i++) {
        if (s[i] == '-') ++dash;
        else ++dot;
    }

    if (dash == 0 || dot == 0) {
        cout<<"YES";
    }
    else if (dash % dot == 0) {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
}
