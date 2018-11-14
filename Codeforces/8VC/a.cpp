#include<iostream>
using namespace std;

bool is_prime(int n) {
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3; i*i<=n; i+=2) {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    if(n%2==1) {
        cout<<3<<endl;
    }
    else  {
        for(int i=1; i<=1000; i++) {
            if( is_prime( i*n + 1) == false ) {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
