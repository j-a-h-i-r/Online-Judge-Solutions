#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r" , stdin);
    int n;
    long long k;
    cin>>n>>k;
    long long ara[26+1] = {0};
    for(int i=0; i<n; i++)
    {
        char c;
        cin>>c;
        ara[ c-'A' ]++;
    }
    sort(ara, ara+26, greater<long long>() );

    long long sum = 0LL;

    for(int i=0; i<26 && k>0 ; i++)
    {
        if( ara[i] > k )
        {
            sum += (long long)k*k;
            break;
        }
        else {
            sum += (long long)(ara[i]*ara[i]);
            k = k-ara[i];
        }
    }

    cout<<sum;
}
