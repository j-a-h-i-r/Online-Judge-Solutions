#include<iostream>
using namespace std;

int main()
{
    int n, one=0;
    cin>>n;
    int ara[n];
    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
        if(ara[i]) one++;
    }
    int zeroOne[2], maxDiff = -1;
    for(int i=0; i<n; ++i)
    {
        zeroOne[0] = 0; zeroOne[1]=0;
        for(int j=i; j<n; ++j)
        {
            zeroOne[ ara[j] ]++;
            int diff = zeroOne[0] - zeroOne[1];
            if( diff < 0 )
            {
                // flipping this part is worse than current
                // state
            }
            else {
                maxDiff = max(maxDiff, diff);
            }
            //cout<<maxDiff<<" "<< diff<<" - ";
        }
        //cout<<endl;
    }
    cout<<one+maxDiff;
    return 0;
}
