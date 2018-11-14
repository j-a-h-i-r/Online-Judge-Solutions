#include<iostream>
using namespace std;
int main()
{
    int n,l,r, ql,qr;
    cin>>n>>l>>r>>ql>>qr;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int el=0, er=0;
    int i=0, j=n-1;
    int cl, cr, cost = 0;
    while(i<=j) {
        cl=a[i]*l+el;
        cr=a[j]*r+er;

        cout<<cl<<" "<<cr<<" "<<cost<<endl;

        if(cl<=cr) {
            el = ql;
            er = 0;
            cost += cl;
            i++;
        }
        else {
            er = qr;
            el = 0;
            cost += cr;
            j--;
        }
    }
    cout<<cost;
    return 0;
}
