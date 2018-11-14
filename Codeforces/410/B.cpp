#include<iostream>
#include<limits>
using namespace std;
int main()
{
    int n, minMoves = INT_MAX;
    cin>>n;
    string s[n];
    for (int i=0; i<n; i++) {
        cin>>s[i];
    }
    int len = s[0].length();
    for (int i=0; i<n; i++) {
        int moves = 0;
        bool matched, finMatch = true;

        for (int j=0; j<n; j++) {
            // let's try to make all strings equal to [i]th one
            matched = false;
            string tmp = s[j];

            for (int l=0; l<len; l++) {
                if (s[i]==tmp) {
                    matched = true;
                    break;
                }
                tmp = tmp.substr(1, string::npos) + tmp[0];
                moves++;
            }
            finMatch = finMatch & matched;
        }
        if (moves < minMoves && finMatch) minMoves = moves;
    }
    if (minMoves == INT_MAX) cout<<"-1";
    else cout<<minMoves;
    return 0;
}
