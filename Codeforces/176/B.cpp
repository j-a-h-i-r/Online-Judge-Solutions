#include<iostream>
using namespace std;
int main()
{
    char ara[4][4];

    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            cin>>ara[i][j];
        }
    }

    for (int i=0; i<=2; ++i) {
        for (int j=0;j<=2; ++j) {
            int hsh=0, dot=0;
            for (int k=i; k<i+2; ++k) {
                for (int l=j; l<j+2; ++l) {
                    if (ara[k][l]=='#') hsh++;
                    else dot++;
                }
            }
            if (hsh==4||dot==4||hsh==3||dot==3) {
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
