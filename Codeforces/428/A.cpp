#include<iostream>
using namespace std;
int main()
{
    int n, k, a;
    int have=0, given=0;

    cin>>n>>k;
    int days = 1, can_be_given;
    for (int i=0; i<n; i++) {
        cin>>a;
        have += a;
        can_be_given = min(8, have);
        given += can_be_given;
        have -= can_be_given;
        if (given<k) days++;
    }
    if (given>=k) cout<<days;
    else cout<<-1;

    return 0;
}
