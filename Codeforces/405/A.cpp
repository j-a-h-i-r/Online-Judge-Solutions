#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    int a, b;
    int cnt = 0;
    cin>>a>>b;
    while(a<=b) {
        a = a*3;
        b = b*2;
        cnt++;
    }
    cout<<cnt;

    return 0;
}
