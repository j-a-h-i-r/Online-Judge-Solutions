#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int x,y,d;
    cin>>x>>y>>d;
    vector<int> data(x*y);

    cin>>data[0];
    int rem = data[0]%d;

    for(int i=1; i<x*y; i++)
    {
        cin>>data[i];
        if(data[i]%d != rem)
        {
            cout<<-1;
            return 0;
        }
    }
    sort(data.begin(), data.end());
    int med = data[ (x*y)/2 ];
    int changes = 0;
    for(int i=0; i<x*y; ++i)
    {
        changes += ( abs(med- data[i]) / d );
    }
    cout<<changes;
    return 0;
}
