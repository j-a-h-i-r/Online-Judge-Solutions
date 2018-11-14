#include<iostream>
using namespace std;

void pr(int &i)
{
    //int y = i+1;
    if( i== 10) return;
    cout<<&i<<" "<<i<<endl;
    i=i+1;
    pr( i );
}

int main()
{
    int i=0;
    pr(i);
}
