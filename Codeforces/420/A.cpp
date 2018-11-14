#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

bool check (int ara[], int x, int n)
{
    int id1, id2;
    for (int i=0; i<2*n-1; i++) {
        if (ara[i]==x) {
            id1 = i;
            break;
        }
    }
    cout<<id1<<endl;
    for (int i=id1-1; i>=0; i--){
        id2 = 0;
        while( id2<id1 && ara[id1]+ara[id2]<=x ) {
            if (ara[id1]+ara[id2]==x) return true;
            id2++;
        }
    }
    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int n;
    cin>>n;
    int ara[n][n];
    bool possible = true;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin>>ara[i][j];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<i<<" "<<j<<endl;
            if (ara[i][j]!=1) {
                cout<<ara[i][j]<<endl;
                // build an array
                // sort it
                // pass to function to evaluate
                int temp[2*n-1], id=0;

                for (int x=0; x<n; x++) {
                    temp[id++] = ara[x][j];
                }
                for (int x=0; x<n; x++) {
                    if (x==j) continue; // that has already been taken
                    temp[id++] = ara[i][x];
                }
                sort(temp, temp + (2*n-1) );

                for (int x=0; x<2*n-1; x++) cout<<temp[x]<<" ";
                cout<<endl;

                possible = check(temp, ara[i][j], n);

                if (possible != true) break;
            }
        }
    }

    if (possible) cout<<"Yes";
    else cout<<"No";

    return 0;
}
