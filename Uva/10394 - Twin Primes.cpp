#include<iostream>
#include<vector>
using namespace std;

const int LIMIT = 20000005;

vector<bool> isPrime(LIMIT, true);
vector<pair<int,int> > twin;

void sieve()
{
    for (int i=2; i*i < LIMIT; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j < LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int lastPrime = 2;
    for (int i=3; i<LIMIT; i+=2) {
        if (isPrime[i]) {
            if ( i - lastPrime == 2 ) {
                twin.push_back(make_pair(lastPrime, i));
            }
            lastPrime = i;
        }
    }
}

int main()
{
    sieve();

    int n;
    while(cin>>n) {
        cout<<"(";
        cout<<twin[n-1].first<<", "<<twin[n-1].second;
        cout<<")";
        cout<<"\n";
    }
    return 0;
}
