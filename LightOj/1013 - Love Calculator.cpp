#include<iostream>
#include<cstring>
using namespace std;

string s1, s2;
int n, m, seqL;
int dp[31][31];
long long dp2[31][31][61];

int lcs(int i, int j)
{
    if(i==n || j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if( s1[i] == s2[j] ) return dp[i][j]=1 + lcs(i+1, j+1);
    else return dp[i][j]=max( lcs(i, j+1), lcs(i+1, j) );
}
long long tot(int i, int j, int num)
{
    if(i==n)
    {
        if( m-j + num == seqL ) return 1;
        else return 0;
    }
    else if(j==m)
    {
        if(n-i+num == seqL) return 1;
        else return 0;
    }
    if(dp2[i][j][num]!=-1) return dp2[i][j][num];
    if( s1[i]==s2[j] ) return dp2[i][j][num]=tot(i+1, j+1, num+1);
    else return dp2[i][j][num]=tot(i+1,j,num+1) + tot(i,j+1,num+1);
}

int main()
{
    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof dp);
        memset(dp2, -1, sizeof dp2);
        cin>>s1>>s2;
        n = s1.length();
        m = s2.length();

        seqL = n + m - lcs(0, 0);

        cout<<"Case "<<++cs<<": ";
        cout<<seqL<<" ";
        cout<<tot(0,0,0)<<endl;
    }
    return 0;
}
