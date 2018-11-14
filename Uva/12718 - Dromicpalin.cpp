#include<iostream>
using namespace std;

int pal(string a, int l, int r)
{
    if(l==r) return 1;

    return pal(a,l,r-1) + pal(a,l+1, r);
}

int main()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;

        cout<<pal(s, 0, s.length()-1)<<endl;
        //cout<<s<<endl;
    }
    return 0;
}
