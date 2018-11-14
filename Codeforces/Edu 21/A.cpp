#include<iostream>
using namespace std;

long long dig(long long x)
{
    long long d = 0;
    while (x != 0) {
        d++;
        x = x/10;
    }
    return d;
}
long long first(long long x)
{
    while (x >= 10) {
        x = x/10;
    }
    return x;
}
long long pow(long long a, long long b)
{
    long long p = 1;
    for (long long i = 1; i<=b; i++) p = p * 10;
    return p;
}

int main()
{
    long long n;
    cin>>n;

    long long digits = dig(n);
    long long firstDigit = first(n);
    long long next = (firstDigit+1) * pow(10, digits - 1);

    cout<<next - n;
}
