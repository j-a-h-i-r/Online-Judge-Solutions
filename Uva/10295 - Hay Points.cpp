#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    int m,n;
    cin>>m>>n;
    string job;
    double pay;
    map<string, double> mp;
    while(m--)
    {
        cin>>job>>pay;
        mp[job] = pay;
    }
    while(n--)
    {
        double sum = 0;
        while(cin>>job)
        {
            if(job==".") break;
            if( mp.find(job)!=mp.end() ) sum+=mp[job];
        }
        cout<<sum<<"\n";
    }
    return 0;
}
