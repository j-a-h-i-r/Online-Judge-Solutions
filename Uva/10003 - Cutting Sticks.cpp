#include<iostream>
using namespace std;

int cut(int left, int right, int dist[])
{
    int cost[right+1][right+2];
    for(int i=0; i<=right; i++) {
        cost[i][i] = 0;
        cost[i][i+1] = 0;
    }

    for(int part=2; part<=right; part++)
    {
        for(int i=left; i<=right-part; i++)
        {
            int j = i + part;
            cost[i][j] = 9999;

            for(int k=i+1; k<j; k++)
            {
                int m = cost[i][k] + cost[k][j] + (dist[j]-dist[i]);
                if(m<cost[i][j])
                {
                    cost[i][j] = m;
                }
            }
        }
    }
    return cost[left][right];
}

int main()
{
    int length;
    while(cin>>length)
    {
        if(length==0) break;
        int n;
        cin>>n;
        int dist[n+2];
        dist[0] = 0;
        dist[n+1] = length;
        for(int i=1; i<=n; i++) cin>>dist[i];

        int mC = cut(0,n+1,dist);
        cout<<"The minimum cutting is "<<mC<<".\n";
    }
    return 0;
}

