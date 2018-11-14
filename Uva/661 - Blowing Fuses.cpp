#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m, c, seq = 0;
    while (cin>>n>>m>>c) {
        if ( !(n||m||c) ) break;
        vector<bool> active(n+5, false);
        vector<int> power(n+5);
        int device, consume = 0, maxConsume = -1;
        bool fused = false;
        for (int i=1; i<=n; i++) {
            cin>>power[i];
        }
        for (int i=1; i<=m; i++) {
            cin>>device;
            if (active[device]) {
                active[device] = false;
                consume -= power[device];
            }
            else {
                consume += power[device];
                active[device] = true;
                maxConsume = max(maxConsume, consume);
                if (consume > c) {
                    fused = true;
                }
            }
        }
        cout<<"Sequence "<<++seq<<"\n";
        if (fused) {
            cout<<"Fuse was blown.";
        }
        else {
            cout<<"Fuse was not blown.";
            cout<<"\n";
            cout<<"Maximal power consumption was "<<maxConsume<<" amperes.";
        }
        cout<<"\n\n";
    }
    return 0;
}
