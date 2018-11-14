#include<iostream>
#include<map>
#include<queue>
using namespace std;
int main()
{
    queue<long long> q;
    map<long long, long > mp;
    long long n;
    while(cin>>n)
    {
        if(mp.find(n)!=mp.end())
        {
            mp[n]++;
        }
        else {
            mp[n]=1;
            q.push(n);
        }
    }
    while(!q.empty())
    {
        cout<<q.front()<<" "<<mp[q.front()]<<"\n";
        q.pop();
    }
    return 0;
}
