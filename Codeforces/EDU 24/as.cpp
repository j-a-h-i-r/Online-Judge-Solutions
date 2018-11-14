#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define lim 100000000
int main()
{
    srand(time(NULL));
    static int a[lim];
    for (int i=0; i<lim; i++) a[i] = i+1;

    for (int i=0; i<lim; i++) {
        int idx = i + rand()%(lim-i);
        //cout<<idx<<endl;
        swap(a[i], a[idx]);
    }
    //for (int i=0; i<lim; i++) cout<<a[i]<<" ";
}
