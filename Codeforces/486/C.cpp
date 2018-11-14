#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    int sumr[k];
    bool found = false;
    int x, n, numi, numj, y;
    int ai, aj;
    map<int, int> mp[k];

    for (int i=0; i<k; i++) {
        cin>>n;
        //map<int, bool> mp;
        int sum = 0;
        for (int j=0; j<n; j++) {

            cin>>x;
            mp[i][x] = j;
            sum += x;
        }

        if (found) continue;
        for (int j=0; j<i; j++ )  {
            int diff1 = sum-sumr[j];
            //int diff2 = sumr[j]-sum;

            if (diff1>0) {
            if (mp[i].find(diff1) != mp[i].end() && mp[j].find(-diff1)!= mp[j].end()) {
                found = true;
                ai = j;
                aj = i;
                numi = diff1;
                numj = -diff1;
            }}
            else if (mp[i].find(-diff1) != mp[i].end() && mp[j].find(diff1)!= mp[j].end()) {
                found = true;
                ai = j;
                aj = i;
                numi = -diff1;
                numj = diff1;
            }
        }

        sumr[i] = sum;
    }
    if (found) {
        cout<<"YES\n";
        cout<<ai+1<<" "<<mp[ai][numi] + 1<<"\n";
        cout<<aj+1<<" "<<mp[aj][numj] + 1<<"\n";
    }
    else {
        cout<<"NO";
    }
}
