#include<bits/stdc++.h>
using namespace std;

void inSort(int ar[], int n)
{
    while(n>1 && ar[n-1]>ar[n]) {
        swap(ar[n-1], ar[n]);
        n--;
    }
}

int main()
{
    int arr[10005];
    arr[0] = -1;
    int n, l=1, x, y;
    while(cin>>n) {
        arr[l] = n;

        inSort(arr, l);
        //for(int i=1; i<=l; i++) cout<<arr[i]<<" ";
        //cout<<endl;

        if ( ((1+l)) % 2 == 0) {
            cout<<arr[ (1+l)/2 ]<<"\n";
        }
        else {
            x = (1+l)/2;
            cout<<(arr[x]+arr[x+1])/2<<"\n";
        }

        ++l;
    }
    return 0;
}
