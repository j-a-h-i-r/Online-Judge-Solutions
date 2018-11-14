#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    int n,m;
    cin>>n>>m;
    bool actor[n][m];
    int x ;
    int left[n],right[n], up[m],down[m];

    for(int i=0; i<m; i++) {
        up[i] = 9999; down[i] = -1;
    }
    for(int i=0; i<n; i++)
    {
        left[i] = 9999; right[i] = -1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>x;
            if(x==1) {
                actor[i][j] = true;
                if( j<left[i] ) left[i] = j;
                right[i] = j;
                if( i<up[j] ) up[j] = i;
                down[j] = i;
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if( !actor[i][j] )
            {
                if( j>left[i]  ) {
                    cnt++;
                    //cout<<i+1<<","<<j+1<<" left\n";
                }
                if( j<right[i] ) {
                    cnt++;
                    //cout<<i+1<<","<<j+1<<" right\n";
                }
                if( i>up[j] ) {
                    cnt++;
                    //cout<<i+1<<","<<j+1<<" up\n";
                }
                if( i<down[j] ) {
                    cnt++;
                    //cout<<i+1<<","<<j+1<<" down\n";
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
