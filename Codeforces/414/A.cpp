#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
    int n;
    cin>>a>>b>>c;
    cin>>n;

    int notes = 0, x;

    for (int i=0; i<n; i++) {
        cin>>x;

        if (x>b && x<c) notes++;
    }

    cout<<notes<<endl;
    return 0;
}
