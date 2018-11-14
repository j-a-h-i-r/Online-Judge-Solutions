#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];
    if (n==1) {
        cout<<-1;
    }
    else if (n==2 && a[0]==a[1]) {
        cout<<-1;
    }
    else {
        int mn = a[0];
        int mni = 0;
        for (int i=0; i<n; i++) {
            if (a[i] < mn) {
                mn = a[i];
                mni = i;
            }
        }
        cout<<1<<"\n";
        cout<<mni + 1;
    }
    return 0;
}
