#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

double s_time[100002];
vector<int> v[100002];

double cur_time = 0;

void dfs(int u)
{
    cur_time = cur_time + 1;
    s_time[u] = cur_time;

    for(int i = v[u].size()-1; i>0; i-- )
    {
        int j = rand()%(i+1);

        swap(v[u][i], v[u][j]);
    }

    for(int x = 0; x < v[u].size(); x++ )
    {
        dfs( v[u][x] );
    }
}


int main()
{
    srand(time(NULL));

    int n;
    cin>>n;

    for(int i = 1; i<n; i++)
    {
        int pi;
        cin>>pi;

        if(i==pi) continue;

        v[i].push_back(pi);
        v[pi].push_back(i);
    }

    for(int i = 1; i<n; i++)
    {
        cout<<v[i].size();
    }

    dfs( 1 );

    for(int i=0; i<n; i++)
    {
        printf("%.6lf ", s_time[i]);
    }
}
