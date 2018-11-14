#include<iostream>
using namespace std;
int main()
{
    long one = 1;        // first value
    long two = 2;        // second value
    long three;          // third value. sum of 1st an 2nd value will be kept here
    long sum=2;

    while(1) {
        three = one + two;
        cout<< "three" << three <<endl;

        if(three>4000000) {
            break;
        }

        if((three%2) == 0) {
            sum = sum + three;
            cout<< "\t sum" << sum << endl;
        }

        one = two;
        two = three;
    }

    cout<< sum<< endl;
}
