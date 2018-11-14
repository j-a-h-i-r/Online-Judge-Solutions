#include<iostream>
#include<algorithm>
using namespace std;

long long temp[100005];

long long calcCost(long long a[], int n, long long k) {
    for (int i=0; i<n; i++) {
        temp[i] = a[i] + (i+1)*k;
    }
    sort(temp, temp+n);
    long long cost = 0;
    for (int i=0; i<k; i++) {
        cost += temp[i];
    }
    return cost;
}

int main()
{
    long long n;
    long long s;
    cin>>n>>s;

    long long ara[n];
    long long cost_for_n = 0;
    for(int i=0; i<n; i++) {
        cin>>ara[i];
        cost_for_n += ara[i] + (i+1)*n;
    }
    //cost_for_n *= n;

    int low = 0;    long long lowCost = 0;
    int high = n;   long long highCost = cost_for_n;
    int mid;        long long midCost;
    int ans = -1;   long long cost = -1;

    while(low <= high) {
        mid = (low+high) / 2;
        midCost = calcCost(ara, n, mid);

        if (midCost > s) {
            // can't buy that much
            // buy lower
            high = mid-1;
        }
        else {
            // can buy. possible solution.
            // let's try to buy some more things
            ans = mid;
            cost = midCost;
            low = mid+1;
        }
    }

    if (ans==-1) {
        cout<<"0 0";
    }
    else {
        cout<<ans<<" "<<cost;
    }
    return 0;
}
