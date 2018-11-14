#include<iostream>
using namespace std;

int notmatch( string s )
{
    int ln = s.length(), cnt = 0;
    for (int i=0, j=ln-1; i<j; i++, j--) {
        if ( s[i]!=s[j] ) cnt++;
    }
    return cnt;
}

int main()
{
    string s;
    cin>>s;
    int m = notmatch(s);
    if (m==1) cout<<"YES";
    else if (m==0 && s.length()%2 == 1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
