#include<iostream>
using namespace std;
int main()
{
    int unit;
    cin>>unit;

    if(unit <= 100)  // unit 100 er kom
    {
        bill = unit*15;
        cout<<bill;
    }
    else if( unit>100 && unit<=300 ) // unit 100 theke 300 er moddhe
    {
        int extraUnit = unit - 100;
        bill = 100*15 + extraUnit*18;
    }
}
