#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int root = sqrt(n);

    if (root*root == n) {
        cout<< 4 * root;
    }
    else {
        int komDiff = n - (root*root);
        int besiDiff = (root+1)*(root+1) - n;

        if (komDiff < besiDiff) {
            cout<< (4*root) + 2;
        }
        else {
            cout<< 4 * (root+1);
        }
    }
    return 0;
}
