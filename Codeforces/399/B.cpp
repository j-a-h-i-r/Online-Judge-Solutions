#include<iostream>
using namespace std;

long long len(long long n)
{
    long long x = 1;
    while(n>1) {
        n/=2;
        x*=2;
    }
    return 2*x-1;
}

int get_one(long long target, long long len, long long num)
{
    if(num<2) {
        // can't be divided more
        // if it's 0 then target index is 0
        // if it's 1 then target index is 1
        return num;
    }
    if( len+1 == 2*target ) {
        // the target is in the middle of total array
        // the middle contains   num%2
        return num%2;
    }
    // i haven't found it
    // i have to divide the number again
    num /= 2;
    // so the final length shoul also be half
    len/=2;

    if( target > len+1 ) {
        // target resides in right part of segment
        // but right and left part is exactly same
        // so change target to be in left part
        target -= (len+1);
    }
    return get_one(target, len, num);
}

int main()
{
    long long int n, l, r;
    cin>>n>>l>>r;

    // get fianl len
    long long f = len(n), ans = 0;

    // get 1's in position l to r

    for(long long int i=l; i<=r; i++) {
        ans += get_one(i, f, n);
    }
    cout<<ans<<endl;

    return 0;
}
