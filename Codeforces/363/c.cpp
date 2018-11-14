#include<bits/stdc++.h>
using namespace std;

int events[105];
int n;
int dp_arr[101][4];

int dp(int i, int pre_action) {
    if (i>=n) return 0;

    if (dp_arr[i][pre_action] != -1) return dp_arr[i][pre_action];

    int res, res1, res2, res3;

    if (events[i] == 0) {
        // must take rest
        // add 1 more rest.
        // go to next day
        res = 1 + dp(i+1, 0);
    }
    else if (events[i]==1 || events[i]==2) {
        // can only do contest || sport

        // if previous action is also same as the current event then can't the same thing again
        // else do contest or rest
        if (pre_action == events[i]) {
            res = 1 + dp(i+1, 0);
        }
        else {
            // do contest || sport ==> events[i]
            res1 = 0 + dp(i+1, events[i]);
            // take rest
            res2 = 1 + dp(i+1, 0);

            res = min(res1, res2);
        }
    }
    else if (events[i]==3) {
        // have both contest and sport
        if (pre_action==0) {
            // took rest in previous day
            // so, may do contest or sport

            // contest
            res1 = 0 + dp(i+1, 1);
            // sport
            res2 = 0 + dp(i+1, 2);
            // rest
            res3 = 1 + dp(i+1, 0);

            res = min(res1, min(res2, res3));
        }
        else if (pre_action == 1) {
            // did contest on previous day

            // do sport
            res1 = 0 + dp(i+1, 2);
            // rest
            res2 = 1 + dp(i+1, 0);

            res = min(res1, res2);
        }
        else if (pre_action == 2) {
            // did sport on previous day

            // do contest
            res1 = 0 + dp(i+1, 1);
            // rest
            res2 = 1 + dp(i+1, 0);

            res = min(res1, res2);
        }
    }

    dp_arr[i][pre_action] = res;
    return res;
}

int main()
{
    memset(dp_arr, -1, sizeof(dp_arr));

    cin>>n;

    for (int i=0; i<n; i++) {
        cin>>events[i];
    }

    int ans = dp(0, 0);
    cout<<ans;
    return 0;
}
