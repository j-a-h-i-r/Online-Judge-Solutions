#include<iostream>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;

    int cnt[26][26];
    for(int i=0; i<26; i++) {
        for(int j=0; j<26; j++) {
            cnt[i][j] = 0;
        }
    }

    for (int i=1; i<n; i++) {
        cnt[s[i-1] - 'A'][s[i] - 'A']++;
    }

    int fr=0, se=0, mx = 0;

    for (int i=0; i<26; i++) {
        for(int j=0; j<26; j++) {
            if (cnt[i][j]>mx) {
                mx = cnt[i][j];
                fr = i;
                se = j;
            }
        }
    }

    cout<<char('A' + fr) << char('A'+se);
}
