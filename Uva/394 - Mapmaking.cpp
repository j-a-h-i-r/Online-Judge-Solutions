#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<cstdio>
typedef long long ll;
using namespace std;
int main()
{
    //freopen("in.txt","r", stdin);
    int n,r;
    string name;
    map<string, vector<ll> > mp ;
    cin>>n>>r;
    while(n--)
    {
        cin>>name;
        vector<ll> vec;
        ll b,s,d, l, u;
        cin>>b>>s>>d;
        vec.push_back(b);vec.push_back(s);vec.push_back(d);
        //cout<<vec[0]<<" "<<" "<<vec[1]<<" "<<vec[2]<<"\n";
        for(int i=0; i<d; i++)
        {
            cin>>l>>u;
            vec.push_back(l);
            vec.push_back(u);
            //cout<<l<<" "<<u<<" ";
        }
        //cout<<"\n";
        mp[name] = vec;
    }
    while(r--)
    {
        cin>>name;
        stringstream ss;
        string line;
        getline(cin, line);
        ss<<line;
        ll m;
        vector<ll> id;
        while( ss>>m ) id.push_back(m);

        cout<<name;
        cout<<"[";
        cout<<id[0];
        for(int i=1; i<id.size(); i++) {
            cout<<", "<<id[i];
        }
        cout<<"] = ";

        vector<ll> data = mp[name];
        ll ans = data[0];

        int j = (data.size() - 3)/2;
        vector<ll> cval( j+1 );
        cval[j--] = data[1];
        for(int i=data.size()-1; i>=3; i-=2, j--)
        {
            cval[j] = cval[j+1]*( data[i] - data[i-1] +1 );
        }
        int i;
        for(i=3, j=1; i<data.size(); i+=2, j++)
        {
            ans += cval[j]*( id[j-1] - data[i] );
        }

        cout<<ans<<"\n";
    }
    return 0;
}
