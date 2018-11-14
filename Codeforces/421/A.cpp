#include<iostream>
using namespace std;
int main()
{
    int c, v0, v1, a, l;
    cin>>c>>v0>>v1>>a>>l;
    int read = 0, days = 0, advance = 0;
    while( 1 )
    {
        if (read >= c) break;
        advance = v0 + (days)*a;
        advance = min(advance, v1);
        advance = max(advance - l*(days!=0) , 0);
        read += advance;
        days++;
    }
    cout<<days<<endl;
}
