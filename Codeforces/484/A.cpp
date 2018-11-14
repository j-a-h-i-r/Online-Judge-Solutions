#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int cnt = 0;
    int len = s.length();
    for(int i=0; i<s.length(); i++)
    {
        if (s[i]=='1')
            cnt++;
    }

    if(len == 1 && s[0]=='0') {
        cout<<"No";
    }
    else if(len >= 2 && s[0]=='0' && s[0]==s[1]) {
        cout<<"No";
    }
    else if(len >= 3 && s[len-1]=='0' && s[len-1]==s[len-2]) {
        cout<<"No";
    }
    else
    {
        for(int i=1; i<len; i++) {
            if(s[i-1]=='1' && s[i-1] == s[i] ) {
                cout<<"No";
                return 0;
            }
        }

        for(int i=0; i<len; i++) {
            if(s[i]=='0' && i+2<len && s[i+1]=='0' && s[i+2]=='0') {
                cout<<"No";
                return 0;
            }
        }

        cout<<"Yes";
        return 0;
    }
    return 0;
}
