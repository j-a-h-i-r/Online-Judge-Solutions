#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()

{
    srand(time(NULL));

    freopen("in.txt", "w", stdout);

    int n=1e6;
    long num = 0;
    cout<<n<<endl;
    for (int i=0; i<n;i++) {
        num = rand()% int(2);
        cout<<num<<" ";
    }
}
