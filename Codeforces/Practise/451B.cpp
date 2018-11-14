#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long ara[n+2], sorted[n+1], val;
    ara[0] = -1;
    ara[n+1] = 1e9+5;

    for(int i=1; i<=n; i++)
    {
        cin>>val;
        ara[i] = val;
    }

    int left=0, right=n, smallest = -1, largest = 1e9 + 5;

    for(int i=1; i<n; i++)
    {
        if( ara[i] > ara[i+1] )
        {
            left = i;
            smallest = ara[i-1];
            break;
        }
    }

    //cout<<left<<" "<<smallest<<endl;

    if( left == 0 )
    {
        // sorted array
        cout<<"yes\n1 1";
        return 0;
    }

    for(int i=n; ara[i] > 0; --i)
    {
        if( ara[i] < ara[i-1] || ara[i] < smallest )
        {
            right = i;
            largest = ara[i+1];
            break;
        }
    }

    //cout<<right<<" "<<largest<<endl;

    ara[right+1] = -1;

    for(int i=left; i <= right; ++i)
    {
        if( ara[i] < smallest || ara[i] > largest ||
           ara[i] < ara[i+1]  )
        {
            cout<<"no";
            return 0;
        }
    }
    /*if( ara[right] < smallest || ara[right] > largest )
    {
        cout<<"no";
        return 0;
    }*/

    cout<<"yes\n"<<left<<" "<<right;

    return 0;
}
