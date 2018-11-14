#include<iostream>
#include<cstdio>
using namespace std;

void prSub(int is, int ie, int js, int je, int ara[200][200])
{
    for (int k=is; k<=ie; k++)
    {
        for (int l=js; l<=je; l++)
        {
            cout<<ara[k][l]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int ara[200][200];
    int n;
    while(cin>>n)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>ara[i][j];
            }
        }

        int sum = 0, mxSum = -100000, colSum[200];
        // colsum keeps track of sum in same row of previous column

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                // start at [i][j]
                // traverse
                //sum = 0;
                for (int k=j; k<n; k++)     // column
                {
                    sum = 0;
                    for (int l=i; l<n; l++)     // row
                    {
                        //prSub(i,l, j,k, ara); cout<<endl;
                        sum += ara[l][k];
                        if(k==j)colSum[l] = 0;
                        colSum[l] += sum;
                        //cout<<"s "<<sum<<" "<<colSum[l]<<endl;
                        if (colSum[l] > mxSum)
                        {
                            mxSum = colSum[l];
                        }
                    }
                    //cout<<endl;
                }
            }
        }
        cout<<mxSum<<endl;
    }
    return 0;
}
