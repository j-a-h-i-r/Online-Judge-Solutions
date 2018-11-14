#include<iostream>
#include<cmath>
using namespace std;


static bool not_prime[1000005] = {false};

void sieve()
{
    not_prime[1] = true;

    int limit = 1000000;

    for (int i=2; i*i<=limit; ++i) {

        if (not_prime[i] == true) continue;

        for (int j=2; i*j <=limit; ++j) {
            not_prime[i*j] = true;
        }
    }
}


int main()
{
    int n;
    long long int num;
    long long root;
    cin>>n;

    sieve();

    for (int i=0; i<n; ++i) {
        cin>>num;

        root = sqrt(num);

        if (root*root == num) {

            if (not_prime[root] == false) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}
