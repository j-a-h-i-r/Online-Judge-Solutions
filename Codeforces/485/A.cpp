#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> v;
    v.push_back("Power");
    v.push_back("Time");
    v.push_back("Space");
    v.push_back("Soul");
    v.push_back("Reality");
    v.push_back("Mind");
    bool b[6] = {true, true, true, true, true, true};

    int n, cnt=0;
    cin>>n;
    cout<<n<<endl;
    string s;
    while(n--) {
        cin>>s;
        if (s=="purple") b[0] = false;
        if (s=="green") b[1] = false;
        if (s=="blue") b[2] = false;
        if (s=="orange") b[3] = false;
        if (s=="red") b[4] = false;
        if (s=="yellow") b[5] = false;
    }


    cout<< 6 - n<<endl;
    for (int i=0; i<6; i++) {
        if (b[i]) cout<<v[i]<<"\n";
    }
    return 0;
}

