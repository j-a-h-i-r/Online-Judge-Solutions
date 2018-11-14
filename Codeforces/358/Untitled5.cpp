#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long  i,j,k,c,x,y,l,t,z;
    cin>>x>>y;
    if(x>=y)
    {
        k=x;
        l=y;
    }
    else
    {
        k=y;
        l=x;
    }
    t=k;
    c=0;
    z=1;

    while(t--)
    {
        for(j=1; j<=l; j++)
        {
            if((z+j)%5==0)
            {
                c++;
            }
        }
        z++;
    }
    cout<<c<<endl;
    return 0;
}
