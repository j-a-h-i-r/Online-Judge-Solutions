#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;

    char a[m+1][n+1];
    int i, j;

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    bool found = false;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++) if( a[i][j]=='X' ) {
            found=true;
            break;
        }
        if(found) break;
    }

    int k=0;
    for(k=j; k<n; k++) if(a[i][k]!='X') break;
    k--;
    int l=0;
    for(l=i; l<m; l++) if(a[l][j]!='X') break;
    l--;

    //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;

    bool poss = true;

    for(int y=i; y<=l; y++)
    {
        for(int x=j; x<=k; x++) {
            if(a[y][x]=='X') a[y][x] = '.';
            else poss = false;
        }
    }

    /*for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<a[i][j];
        }
    }*/

    if(!poss) {
        cout<<"NO";
        return 0;
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++) if(a[i][j]!='.'){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}
