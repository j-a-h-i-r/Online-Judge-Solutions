#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin>>a>>b;

    int la = a.length();
    int lb = b.length();

    int i=la, j = lb;

    while( i>0 && j>0 && a[i-1] == b[j-1] ) {
        i--;
        j--;
    }

    cout<<la+lb- ( la-(i) ) - (lb-(j));
}
