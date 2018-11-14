#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

int main()
{
    int n, m, d;
    int x;
    vector<pair<int,int>>::iterator data;
    cin>>n>>m>>d;
    vector<pair<int, int> >sorted(n);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        cin>>sorted[i].first;
        sorted[i].second = i;
    }
    sort(sorted.begin(), sorted.end());

    /*for (int i=0; i<n; i++) {
        cout<<sorted[i].first<<" ";
    } cout<<endl; */


    int day = 1;
    int z;

    while(!sorted.empty()) {
        z = sorted.front().first;
        x = z + d + 1;
        ans[sorted.front().second] = day;
        sorted.erase(sorted.begin());
        while (true) {
            data = lower_bound(sorted.begin(), sorted.end(), pair<int,int>(x, 0), comp);
            if (data == sorted.end()) break;
            //cout<<(*data).first<<" "<<day<<"\n";
            x = (*data).first + d + 1;
            //ans[mp[(*data).second]] = day;
            ans[ (*data).second] = day;
            sorted.erase(data);
        }
        day ++;
    }

    cout<<day-1<<"\n";
    for (int i=0; i<n; i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
