#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
//typedef vector<vector<ll> > matrix;
const ll MOD = 1e9 + 7;

struct matrix {
    ll ara[2][2];
};

ll mod( long long a )
{
    ll res = a%MOD;
    if(res<0) res += MOD;
    return res;
}

matrix mul(matrix A, matrix B)
{
    matrix C;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            ll sum = 0;
            for(int k=0; k<2; k++)
            {
                //C[i][j]+=mod(A[i][k]*B[k][j]);
                sum += mod( A.ara[i][k]*B.ara[k][j] );
            }
            C.ara[i][j] = sum;
        }
    }
    return C;
}
matrix pow(matrix A, long n)
{
    if(n==1) return A;
    if(n%2) return mul(A, pow(A, n-1) );
    matrix X = pow(A, n/2);
    return mul(X,X);
}

ll nth( matrix T, matrix B, ll n)
{
    // raise T's power to n-2
    T = pow(T, n);
    // multiply first row and column to get the first element
    ll res = T.ara[0][0]*B.ara[0][0] +
            T.ara[0][1]*B.ara[1][0];
    return mod(res);
}

int main()
{
    long x, y, n;
    cin>>x>>y>>n;

    // base cases
    if(n==1) { cout<<mod(x); return 0; }
    if(n==2) { cout<<mod(y); return 0; }

    //construct Transformation matrix
    matrix T;
    T.ara[0][0] = 1; T.ara[0][1] = -1;
    T.ara[1][0] = 1; T.ara[1][1] = 0;
    // construct Base matrix
    matrix B;
    B.ara[0][0] = y;
    B.ara[1][0] = x;

    // get nth term
    ll ans = nth( T, B, n-2 );
    cout<<ans;
    return 0;
}
