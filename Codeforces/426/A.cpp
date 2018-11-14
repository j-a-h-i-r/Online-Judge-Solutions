#include<iostream>
using namespace std;

int ret(char ch)
{
    if (ch=='v') return 0;
    if (ch=='<') return 1;
    if (ch=='^') return 2;
    if (ch=='>') return 3;
}

int main()
{
    long n;
    char sign[] = "v<^>";
    char a, b;
    cin>>a>>b>>n;

    int spin = n%4;

    int apos = ret(a);
    int bpos = ret(b);

    if (n%2==0) cout<<"undefined";
    else if (b == sign[(apos+spin)%4]) cout<<"cw";
    else {
        int c = (apos<spin)? apos-spin+4: apos-spin;

        if (b==sign[c]) cout<<"ccw";
        else cout<<"undefined";
    }

    return 0;
}
