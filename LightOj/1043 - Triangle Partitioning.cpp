#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double area(double a, double b, double c)
{
    double s = (a+b+c)/2;
    return sqrt (s*(s-a)*(s-b)*(s-c));
}

int main()
{
    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        double ab,ac,bc, r, ad,ae,de,mid, large, small,trap;
        cin>>ab>>ac>>bc>>r;
        double l=0, h=ab;
        while(l<=h)
        {
            mid=(l+h)/2;
            ae = (mid/ab)*ac;
            de = (mid/ab)*bc;
            large = area(ab,ac,bc);
            small = area(mid,ae,de);
            trap = large - small;
            if( abs((small/trap)-r) < 1e-7 ) {
                break;
            }
            else if( (small/trap) < r ) {
                l=mid;
            }
            else h=mid;
        }
        cout<<"Case "<<++cs<<": ";
        cout.precision(7);
        cout<<fixed<<mid<<"\n";
    }
    return 0;
}
