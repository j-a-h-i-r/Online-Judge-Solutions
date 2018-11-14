#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int cnt = 0;

    for (int l=1; l<n; l++) {
        if ( (n-l) % l == 0) {
            ++cnt;
        }
    }
    cout<<cnt;
    return 0;
}
