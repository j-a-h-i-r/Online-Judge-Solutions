#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ara[n];
    for (int i=0; i<n; i++) cin>>ara[i];

    int id=0;
    while (id < n-1)
    {
        if (ara[id] >= ara[id+1]) break;
        id++;
    }
    while (id < n-1)
    {
        if (ara[id] != ara[id+1]) break;
        id++;
    }
    while (id < n-1) {
        if (ara[id] <= ara[id+1]) break;
        id++;
    }

    if (id == n-1) cout<<"YES";
    else cout<<"NO";

    return 0;
}
