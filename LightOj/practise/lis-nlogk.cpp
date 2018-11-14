#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n = 11;
    int ara[] = {0, 8,1,9,8,3,4,6,1,5,2};
    int l[] = {1,1,1,1,1,1,1,1,1,1,1};
    int in[n];

    in[0] = INT_MIN;
    for(int i=1; i<n; i++) in[i] = INT_MAX;
    int *it, x;
    for(int i=1; i<n; i++) {
        // get number from sequence;
        it = lower_bound(in, in+n, ara[i]);
        //j = it - ara;
        if(it == in+n) {
            cout<<ara[i]<<" not found\n";
        }
        else {
            cout<<ara[i]<<" goes in "<< it-in<<endl;
            x = it - in;
            in[x] = ara[i];
            l[i] = x;
        }
    }
    cout<<endl;

    for(int i=1; i<n; i++) cout<<l[i]<<" ";

}

