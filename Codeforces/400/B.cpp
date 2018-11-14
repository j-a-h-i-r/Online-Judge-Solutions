#include<iostream>
using namespace std;

bool is_prime[100005];

void sieve( ) {
    for(int i=2; i*i<100005; i++) {
        for(int j=i*2; j<100005; j+=i) {
            is_prime[j] = true;
        }
    }
}

int main()
{
    sieve();

    int n;
    cin>>n;
    if (n<=2) {
        cout<<1<<"\n";
        for(int i=1; i<=n; i++) {
            cout<<1<<" ";
        }
        return 0;
    }

    cout<<2<<"\n";

    for(int i=2; i<=n+1; i++) {
        if(is_prime[i] == false) {
            cout<<1<<" ";
        }
        else cout<<2<<" ";
    }
    return 0;
}
