#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    long long n;
    while(cin>>n)
    {
        cout<<n-1<<"\n";
        /*long long matches = 0;
        long long players = n;

        while(players > 1)
        {
            matches += players/2;
            players = (players/2) + (players%2);
        }
        cout<<matches<<"\n";*/
    }
    return 0;
}
