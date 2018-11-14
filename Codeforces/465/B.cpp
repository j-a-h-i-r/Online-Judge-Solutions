#include<iostream>
using namespace std;
int main()
{
    int n;
    string moves;
    cin>>n;
    cin>>moves;

    int x=0, y=0;
    int cur_kingdom = -1;   // kingdom above line = 1
                        // kingdom below line = 0
    int pre_kingdom = -1;
    int last_valid = -1;
    int coins = 0;

    for (int i=0; i<n; i++) {
        if (moves[i] == 'U') {
            // go up
            ++y;
        }
        else if (moves[i] == 'R') {
            // go right
            ++x;
        }

        if (y > x) cur_kingdom = 1;
        else if (y < x) cur_kingdom = 0;
        else cur_kingdom = -1;
        // cout<<cur_kingdom<<" "<<pre_kingdom<<" "<<last_valid<<endl;
        if (cur_kingdom != last_valid && last_valid != -1 && cur_kingdom != -1) {
            ++coins;
        }
        //pre_kingdom = cur_kingdom;
        if (cur_kingdom != -1) last_valid = cur_kingdom;
    }
    cout<<coins;

    return 0;
}
