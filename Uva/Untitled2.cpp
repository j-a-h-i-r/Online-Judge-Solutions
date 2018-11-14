#include<iomanip>
#include<iostream>
using namespace std;

int grid[][5] = {
{0,3,1,2,9 },
{7,3,4,9,9 },
{1,7,5,5,3 },
{2,3,4,2,5 }
};
int r=4, c=5;

void climb( )
{
    int ara[r+2][c+2];
    for(int i=0; i<=c; i++ ) {ara[0][i] = 99; ara[r+1][i] = 99; }
    for(int i=0; i<=r; i++) {ara[i][0] = 99; ara[i][c+1] = 99;}
    for(int i=1; i<=c; i++) {
        for(int j=1; j<=c; j++) ara[i][j] = grid[i-1][j-1];
    }

    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            int m = min( min(ara[i-1][j],ara[i+1][j] ), min(ara[i][j-1],ara[i][j+1]) );
            ara[i][j] = m + grid[i-1][j-1];
        }
    }
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++) cout<<setw(4)<<ara[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    climb( );
}

