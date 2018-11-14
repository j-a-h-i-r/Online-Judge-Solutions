#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int minCash = 1, h, m, preH, preM, cash = 1;
    cin>>h>>m;
    preH = h; preM = m;
    while(--n)
    {
        cin>>h>>m;
        if( preH == h && preM == m ) cash++;
        else
        {
            if( cash > minCash ) minCash = cash;
            cash = 1;
        }
        preH = h;
        preM = m;
    }
    cout<<max(cash, minCash);
    return 0;
}
