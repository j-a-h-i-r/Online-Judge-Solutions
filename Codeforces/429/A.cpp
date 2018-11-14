#include<iostream>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    int cnt[26];
    bool possible = true;
    for (int i=0; i<26; i++) cnt[i]=0;

    for (int i=0; i<n; i++) {
        cnt[ s[i]-'a' ]++;
        if (cnt[ s[i]-'a' ] > k) possible=false;
    }

    if (possible) cout<<"YES";
    else cout<<"NO";

    return 0;
}
