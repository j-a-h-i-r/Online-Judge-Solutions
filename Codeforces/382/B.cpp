#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    int n, n1, n2;
    cin>>n>>n1>>n2;
    vector<double> w(n);
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
    }
    sort(w.begin(), w.end(),  greater<double>() );

    int mn = min(n1,n2);
    int mx = max(n1,n2);

    int i=0;
    double sum1 = 0, sum2 = 0;
    for(i=0; i<mn; i++) {
        sum1 += w[i];
    }
    for( ; i<mx+mn; i++) {
        sum2 += w[i];
    }

    //cout<<sum1<<" "<<sum2<<"\n";

    double avg;
    avg = double(sum1)/double(mn);
    avg += double(sum2)/double(mx);

    cout.precision(6);
    cout<<fixed<<avg<<"\n";
    return 0;
}
