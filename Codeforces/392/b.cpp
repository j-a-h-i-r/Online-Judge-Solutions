#include<iostream>
#include<map>
#include<cstdio>
using namespace std;

char ch[] = {'R', 'G', 'B', 'Y' };

struct bulb{
    string ans;
    bool found = false;
    bulb() {}
};

bool check(string a, int i, int n) {
    int st = max(i-3, 0);
    int en = min( i+3, n-1 );

    for(int f=st; f<=en; f++) {
        if( f!=i && a[i]==a[f] ) return false;
    }
    return true;
}

bulb place(string s, int i, int n, bulb &f) {
    if( i==n ) {
        if( check(s,i,n) == true ) {
            //cout<<s<<endl;
            f.ans = s;
            //cout<<f.ans;
            f.found = true;
            //ans = s;
            return f;
        }
    }
    if( s[i]=='!' ) {
        for(int j=0; j<4; j++) {
            s[i] = ch[j];
            //cout<<"i="<<i<<" "<<ch[j]<<endl;
            if( check(s,i,n) == false  ) {
                s[i]='!';
                continue;
            }
            if( place( s,i+1, n,f ).found ) return f;
            //return place(s,i+1,n,f);
            //cout<<f.ans<<endl;
        }
        //cout<<"i = "<<i<<" s = "<<s<<endl;
    }
    else {
        //cout<<"i = "<<i<<endl;
        return place(s, i+1, n, f);
    }
    return f;
}

int main()
{
    //freopen("in.txt","r",stdin);

    string s;
    cin>>s;
    bulb f;

    f = place(s,0, s.length(), f);

    //cout<<f.ans<<endl;


    map<char, int> mp;
    mp['R']=0; mp['G']=0; mp['B']=0; mp['Y']=0;

    for(int i=0; i<s.length(); i++) {
        if( s[i]=='!' ) {
            mp[ f.ans[i] ]++;
        }
    }

    cout<<mp['R']<<" "<<mp['B']<<" "<<mp['Y']<<" "<<mp['G'];

}
