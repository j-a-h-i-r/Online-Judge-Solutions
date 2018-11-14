#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int countx(string s)
{
    int x = 0;
    for(int i=0; i<25; i++) if( s[i]=='X') x++;
    return x;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    while(scanf("%d", &n) )
    {
        getchar();

        if(n==0) break;

        string l;
        int minl = 100, maxl = -1;
        vector<int> totx;
        for(int i=0; i<n; i++)
        {
            getline(cin, l);
            int ln = countx(l);
            //cout<<l<<"\n";
            totx.push_back(ln);
            //cout<<ln<<"\n";
            minl = min(minl, ln);
            maxl = max(maxl, ln);
        }
        //cout<<minl << " "<< maxl<<"\n";
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += (maxl - totx[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
