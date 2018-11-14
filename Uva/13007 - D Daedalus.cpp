#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int cards[] = {1,10,100,1000,10000};
    int n,m;
    while(cin>>n>>m)
    {
        int b, d, sum=0, x;
        int won = 0, pos = 0;
        while(m--)
        {
            sum = 0;
            cin>>b>>d;
            for(int i=1; i<n; i++)
            {
                cin>>x;
                sum += x;
            }
            //cout<<sum+d<<"  sum\n";
            if( sum + d <= b ) won += d;
            int i;
            for(i=0; i<5; i++)
            {
                if( cards[i]+sum > b ) break;
            }
            if(i>0) {
                //cout<<cards[i-1]<<"\n";
                pos += cards[i-1];
            }
        }
        cout<<pos-won<<"\n";
    }
    return 0;
}
