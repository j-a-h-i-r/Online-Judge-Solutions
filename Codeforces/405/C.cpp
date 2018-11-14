#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

struct sol {
    string st;
    int f, l;
    sol(string a, int b, int c) {
        st = a;
        f = b;
        l = c;
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    string name[52];
    for(int i=0; i<26; i++) {
        name[i] = char('A'+i);
    }
    for(int i=26; i<52; i++) {
        name[i] = char('A'+i-26);
        name[i] += "a";
    }
    int n,k;
    cin>>n>>k;
    int a[n+1][n+1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            a[i][j] = 1;
        }
    }
    string p, last = "";
    for(int i=1; i<=n-k+1; i++) {
        cin>>p;
        if(p=="NO") {
            name[k+i-1] = name[i];
        }
    }
    for(int i=1; i<=n; i++) {
        cout<<name[i]<<" ";
    }

    return 0;
}

