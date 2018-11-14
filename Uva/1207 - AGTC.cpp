#include<iostream>
using namespace std;

int edist(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    int mn;

    int dist[l1+1][l2+1];

    for (int i=0; i<=l1; i++) dist[i][0] = i;
    for (int i=0; i<=l2; ++i) dist[0][i] = i;

    for (int i=1; i<=l1; ++i) {
        for (int j=1; j<=l2; ++j) {
            mn = min(dist[i-1][j]+1, dist[i][j-1]+1);
            if (s1[i]==s2[j]) {
                mn = min(mn, dist[i-1][j-1]);
            }
            else mn = min(mn, dist[i-1][j-1] + 1);
            dist[i][j] = mn;
        }
    }

    /*cout<<"    ";
    for (int i=0; i<l2; i++) cout<<s2[i]<<" ";
    cout<<endl;
    for (int i=0; i<=l1; i++) {
        if(i>0)cout<<s1[i-1]<<" ";
        else cout<<"  ";
        for (int j=0; j<=l2; j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return dist[l1][l2];
}

int main()
{
    int len1, len2, ans;
    string str1, str2;

    while(cin>>len1>>str1) {
        cin>>len2>>str2;

        ans = edist(str1, str2);
        cout<<ans<<"\n";
    }
}
