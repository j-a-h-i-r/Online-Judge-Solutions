#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long a, b;
    cin>>a>>b;

    long long sq = sqrt( min(a, b) );
    long long at = 0 , bt = 0;

    for (long long i = 1;  ; ++i) {
        if (i%2 == 0) {
            bt += i;
            if (bt > b) {
                cout<<"Valera";
                return 0;
            }
        }
        else {
            at += i;
            if (at > a) {
                cout<<"Vladik";
                return 0;
            }
        }
    }
}
