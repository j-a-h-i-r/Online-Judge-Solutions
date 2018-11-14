#include<iostream>
using namespace std;
int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    int fullvacant = b;
    int halfvacant = 0;
    int g, denied = 0;
    for (int i=0; i<n; i++) {
        cin>>g;

        if (g==1) {
            if (a>0) a--;
            else {
                if (fullvacant>0) {
                    fullvacant--;
                    halfvacant++;
                }
                else if (halfvacant>0) {
                    halfvacant--;
                }
                else denied += g;
            }
        }
        else {
            if (fullvacant>0) {
                fullvacant--;
            }
            else denied += g;
        }
    }

    cout<<denied;

    return 0;
}
