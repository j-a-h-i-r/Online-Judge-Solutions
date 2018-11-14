#include<iostream>
using namespace std;
int main()
{
    int m,d;
    cin>>m>>d;
    int mn[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
    int col = 1;
    int st = 8-d+1;
    while(st<=mn[m]) {
        col++;
        st = st+7;
    }
    cout<<col;
}
