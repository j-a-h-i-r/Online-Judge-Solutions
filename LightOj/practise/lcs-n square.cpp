#include<iostream>
using namespace std;
int main()
{
    int n = 10;
    int ara[] = {8,1,9,8,3,4,6,1,5,2};
    int l[] = {1,1,1,1,1,1,1,1,1,1};

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if( ara[j]>ara[i] ) {
                // ara[j] is in right of ara[i]
                // and it's greater than ara[i];
                if( l[i]+1 > l[j] ) {
                    // we can make a bigger subsequence
                    // by adding ara[j] with ara[i]

                    l[j] = l[i] + 1;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout<<ara[i]<<" ";
    } cout<<endl;
    for(int i=0; i<n; i++) {
        cout<<l[i]<<" ";
    } cout<<endl;
    int x = 4, prev = 10;
    for(int i=6; i>=0; i--) {
        if( l[i] == x && ara[i]<prev ) {
            cout<<ara[i]<<" ";
            x--;
            prev = ara[i];
        }
    }
}
