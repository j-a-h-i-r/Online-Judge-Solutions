#include<iostream>
#include<cmath>
using namespace std;

double cutHere(double ca, double height)
{
    double lo = 0, hi = height, mid;
    double temp_area;

    while( lo < hi ) {
        mid = (lo+hi)/2;
        temp_area = (mid*mid*.5) / height;

        if (abs(temp_area - ca) < 0.00000001) return mid;
        else if (temp_area < ca) {
            lo = mid;
        }
        else hi = mid;
    }
}

int main()
{
    int n, h;
    cin>>n>>h;
    double areaMain = .5 * h;
    double areaChunk = areaMain / n;
    double pos;
    for (int i=1; i<n; i++) {
        pos = cutHere( areaChunk * double(i), double(h) );
        cout.precision(8);
        cout<<fixed<<pos<<" ";
    }
    return 0;
}
