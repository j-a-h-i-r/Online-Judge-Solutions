#include<iostream>
using namespace std;

void no()
{
    cout<<"NO"<<endl;
}
void yes()
{
    cout<<"YES"<<endl;
}

int main()
{
    long long a, b, c;
    cin>>a>>b>>c;

    if(c==0) {
        if(a==b) yes();
        else no();
    }

    else if(c>0) {
        // increasing
        if(b<a) no();
        else if( (b-a)%c == 0 ) yes();
        else no();
    }
    else {
        c = -c;
        // decreasing sequence
        if(b>a) no();
        else if( (a-b)%c == 0 ) yes();
        else no();
    }

    return 0;
}
