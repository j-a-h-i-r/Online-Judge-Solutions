#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][3];
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) cin>>a[i][j];
    }
    int ans[3] = {0,0,0};
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
        {
           ans[j]+=a[i][j];
        }
    }

    if(!ans[0] && !ans[1] && !ans[2]) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
