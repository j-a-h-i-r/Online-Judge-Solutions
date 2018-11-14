#include<iostream>
using namespace std;

int main()
{
    int count = 0;

    int a[5] = {2,-1,5,4,9};

    for(int i=0; i<5; i++)
    {
        for(int j= i+1; i<5; j++)
        {
            if(a[i] > a[j] ) count++;
        }

        cout<<count<<endl;
    }
}
