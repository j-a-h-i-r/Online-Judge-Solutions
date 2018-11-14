#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t, cs=0;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        string s="-", inp;
        cin>>inp;
        s = s+inp+"--";
        int cnt = 0;
        //cout<<s<<"\n";
        for(int i=1; i<=inp.length(); i++)
        {
            if( s[i]!='D'&&s[i]!='B'&&s[i]!='S' )
            {
                if(s[i-1]!='S'&&s[i+1]!='S'&&s[i+1]!='B'&&s[i+2]!='B') {
                    //cout<<i<<" "<<s[i]<<" ";
                    cnt++;
                }
            }
        }
        cout<<"Case "<<++cs<<": "<<cnt<<"\n";
    }
    return 0;
}
