#include<iostream>
#include<cstdio>
using namespace std;

int pos[20];
bool taken[20];

bool is_prime(int x)
{
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3; i<x; i+=2) {
        if(x%i==0) return false;
    }
    return true;
}

void show_perm(int id, int n)
{
    if(id==n) {
        //cout<<pos[0]<<" "<<pos[id-1]<<endl;

        if( is_prime(pos[0]+pos[id-1])==false) return;
        cout<<pos[0];
        for(int i=1; i<n; i++) {
            cout<<" "<<pos[i];
        }
        cout<<"\n";
        return;
    }
    for(int i=2; i<=n; i++) {
        if( taken[i]==false && is_prime(pos[id-1]+i)==true )
        {
            // let's take it
            taken[i] = true;
            pos[id] = i;
            show_perm(id+1, n);
            taken[i] = false;
        }
    }
}

int main()
{
    //freopen("out.txt","w", stdout);

    int n, cs=0;
    while(cin>>n)
    {
        for(int i=0; i<20; i++) {
            taken[i] = false;
            pos[i] = 0;
        }
        pos[0] = 1; taken[1] = true;

        if(cs) cout<<"\n";
        cout<<"Case "<<++cs<<":\n";
        show_perm(1, n);
        //cout<<"\n";
    }
    return 0;
}
