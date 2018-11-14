#include<bits/stdc++.h>
using namespace std;

int main()
{

    while(1)
    {
        int a[105];
        int temp;
        int i,max=0;
        memset(a,0,sizeof(a));
        for(i=0; i<5; i++)
        {
            cin>>temp;
            ++a[temp];
            if(temp>max) max=temp;
        }
        int j=1,c1=0,sum=0,flag=0,k=0;
        for(i=0; i<=max; i++)
        {
            if(a[i]>=j)
            {
                k=i;
                j=a[i];

            }
        }

        for(i=0; i<102; i++)
        {

            while(a[i]--)
            {
                sum=sum+i;
            }
        }

        if(j>=3)
        {
            c1=k*3;
            cout<<sum-c1<<endl;
        }
        else if(j==2)
        {
            c1=k*2;
            cout<<sum-c1<<endl;
        }
        else
            cout<<sum<<endl;
    }

    return 0;
}
