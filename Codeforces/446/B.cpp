#include<iostream>
#include<cstdio>
using namespace std;

long a[1000005];

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    cin>>n;

    //cout<<n;
    //cout<<"hello";
    for (int i=0; i<n;i ++) {
        //cin>>a[i];
        scanf("%ld", &a[i]);
        //cout<<a[i]<<endl;
    }

    int killed = n;
    int reach , pre = 0;
    int alive = 0;

    for (int i=n-1; i>=0; i--) {

        if (killed<=0) break;


        if (i < killed) {
            alive++;
            //cout<<i<<endl;
        }
        int now = i - a[i];

        if (now<killed) killed = now;

        //killed = i - a[i];
    }

    cout<<alive<<"\n";
}
