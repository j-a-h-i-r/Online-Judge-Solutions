#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+1], b[n+1];

    int cnt = 0;

    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) continue;

            if( a[j] == b[i] )
            {
                cnt++;
                a[j] = -1;
            }
        }
    }
    cout<<n-cnt;

    return 0;
}
