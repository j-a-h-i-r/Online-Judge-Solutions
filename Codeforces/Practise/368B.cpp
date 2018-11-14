#include<iostream>
#include<vector>
#include<set>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("in.txt" , "r", stdin);

    int n,m;
    cin>>n>>m;

    vector<int> v(n+1), count(n+1), query(m+1);
    set<int> s;

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        //cout<<v[i]<< " " ;
    }
    //cout<<endl;
    for(int i=0; i<m; i++)
    {
        cin>>query[i];
        //cout<<query[i] << " ";
    }
    //cout<<endl;
    for(int i=n-1; i>=0; i--) {
        s.insert(v[i]);
        count[i] = s.size();
        //cout<< i << " " << s.size() <<endl;
    }

    for(int i=0; i<m; i++)
    {
        cout<<count[ query[i] - 1 ] <<endl;
    }

    return 0;

}
