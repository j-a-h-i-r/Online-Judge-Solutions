#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;
int main()
{
    string oleg, igor;
    cin>>oleg;
    cin>>igor;

    int n = oleg.length();
    vector<char> ans(n);

    sort(oleg.begin(), oleg.end());
    sort(igor.begin(), igor.end(), greater<char>());

    int olS = 0, igS = 0, olE = (n-1)/2, igE = (n-2)/2;
    int aS=0, aE=n-1;

    bool olegChoose = true;

    for (int i=0; i<n; i++) {
        if (olegChoose) {
            // largest of igor smaller than smallest of oleg
            if ( igor[igS] <= oleg[olS] ) {
                // place oleg's biggest at last
                ans[aE] = oleg[olE];
                aE--;
                olE--;
            }
            else {
                ans[aS] = oleg[olS];
                aS++;
                olS++;
            }
            olegChoose = false;
        }
        else {
            // igor's biggest smaller than oleg
            if ( igor[igS] <= oleg[olS] ) {
                // place the smallest at last
                ans[aE] = igor[igE];
                aE--;
                igE--;
            }
            else {
                ans[aS] = igor[igS];
                igS++;
                aS++;
            }
            olegChoose = true;
        }
    }
    for (int i=0; i<n; i++) {
        cout<<ans[i];
    }

    return 0;
}
