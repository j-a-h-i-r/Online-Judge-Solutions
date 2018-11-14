#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vint;

long long fact[20], sumFact[20], tot, number;
int used[20];

int indexOfLast( int i, long long num )
{
    while( (fact[i] > num && i>=0) || used[i]==1) i--;
    // if a number is already used
    // it cant be used anymore
    // find the biggest non-used number
    return i;
}
bool isPossible( int i, long long number )
{
    if( sumFact[i] < number ) return false;
    return true;
}

int main( )
{
    long long facto = 1;
    fact[0] = 1;
    sumFact[0] = 1;
    for(tot = 1;  ; tot++)
    {
        facto = facto*tot;
        if(facto>0 && facto<=1e18) {
            fact[tot] = facto;
            sumFact[tot] = sumFact[tot-1]+fact[tot];
        }
        else {
            --tot;
            break;
        }
    }
    // tot has total possible factorials
    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        cin>>number;

        int i;
        vint ans;
        bool possible = true;
        for(int x=0; x<20; x++) used[x] = 0;
        while( possible && number > 0 )
        {
            i=indexOfLast(tot, number);
            used[i] = 1;
            possible = isPossible( i, number );
            if( possible  )
            {
                ans.push_back( i );
                number = number - fact[i];
            }
            //cout<<i<<"\t"<<fact[i]<<"\t"<<number;
            //cout<<endl;
        }
        if(possible)
        {
            reverse(ans.begin(), ans.end());
            cout<<"Case "<<++cs<<": ";
            cout<<ans[0]<<"!";
            for(int x=1; x<ans.size(); x++)
            {
                cout<<"+"<<ans[x]<<"!";
            }
            cout<<"\n";
        }
        else cout<<"Case "<<++cs<<": impossible\n";
    }

    return 0;
}
