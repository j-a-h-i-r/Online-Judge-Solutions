#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    string s;
    while(cin>>n)
    {
        if(n==0) break;
        cin>>s;

        int ln = s.length();
        int sz = ln/n;

        for(int i=0; i<n; i++)
        {
            int st = i*sz;
            int en = st + sz;
            reverse( s.begin()+st, s.begin()+en );
        }
        cout<<s<<"\n";
    }
    return 0;
}
