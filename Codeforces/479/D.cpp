#include<iostream>
#include<map>
using namespace std;
int n;
long long sol[101];
map<long long, int> mp;

void solve(long long x, int cnt) {
    if(cnt+1 == n) {
        //cout<<"solved\n";
        for(int i=0; i<n; i++) {
            cout<<sol[i]<<" ";
        }
        exit(0);
    }

    //cout<<x<<" "<<cnt<<endl;

    //mp[x] -= 1;
    if (mp.find(x) == mp.end()) return;
    if (mp[x] < 0) return;


    if (x%3 == 0) {
        //if (mp.find(x/2) == mp.end()) return;
        //if (mp[x/2] == 0) return;
        //cout<<x<<" "<<cnt<<endl;
        if (mp.find(x/3) != mp.end()) {
            //cout<<x<<" /3 "<<cnt<<endl;
            sol[cnt+1] = x/3;
            mp[x/3] -= 1;
            solve(x/3, cnt+1);
            mp[x/3] += 1;
        }

        //if (mp.find(x*3) == mp.end()) return;
        //if (mp[x*3] == 0) return;
        if (mp.find(x*2) != mp.end()) {
            //cout<<x<<" *2 "<<cnt<<endl;
            sol[cnt+1] = x*2;
            mp[x*2] -= 1;
            solve(x*2, cnt+1);
            mp[x*2] += 1;
        }
    }
    else {
        //if (mp.find(x*3) == mp.end()) return;
        //if (mp[x*3] == 0) return;
        if (mp.find(x*2) != mp.end()) {
            //cout<<x<<" *2 "<<cnt<<endl;
            sol[cnt+1] = x*2;
            mp[x*2] -= 1;
            solve(x*2, cnt+1);
            mp[x*2] += 1;
        }
    }
}

int main()
{
    cin>>n;
    long long ara[n];
    for (int i=0; i<n; i++) {
        cin>>ara[i];
        if (mp.find(ara[i]) == mp.end()) {
            mp[ara[i]] = 1;
        }
        else {
            mp[ara[i]] += 1;
        }
    }

//    map<long long, int>::iterator it;
//    for (it=mp.begin(); it!=mp.end(); ++it) {
//        cout<<it->second<<" f ";
//    }

    for(int i=0; i<n; ++i) {
        sol[0] = ara[i];
        mp[ara[i]] -= 1;
        solve(ara[i], 0);
        mp[ara[i]] += 1;
    }
}
