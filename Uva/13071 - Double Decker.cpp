#include<iostream>
using namespace std;
int main()
{
    int start[2001];
    start[0] = 1;
    for(int i=1; i<=2000; i++)
    {
        start[i] = start[i-1] + i;
    }


    int t;
    cin>>t;
    while(t--)
    {
        int u,l;
        cin>>u>>l;
        int tot = u+l;

        int st = start[tot];
        cout<<st+u<<"\n";
    }
    return 0;
}
