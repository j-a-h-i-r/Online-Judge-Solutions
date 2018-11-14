#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);

    pair<int,int>a,b,bin;
    pair<int,int> bot1, bot2(-1,-1);
    int n;
    double dist = 0, temp, amax=0, bmax=0, da, db, ak, bk;
    long long x,y;

    cin>>a.first>>a.second>>b.first>>b.second>>bin.first>>bin.second;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>x>>y;

        temp = sqrt( (bin.second-y)*(bin.second-y) + (bin.first-x)*(bin.first-x) );
        dist += 2*temp;

        ak = sqrt((a.second-y)*(a.second-y)+(a.first-x)*(a.first-x));
        bk = sqrt((b.second-y)*(b.second-y)+(b.first-x)*(b.first-x));

        da = temp - ak;
        db = temp - bk;

        if(  da > db  ) {
            if ( da > amax ) {
                if( amax > bmax ) bmax = amax;
                amax = da;
            }
            else if( da > bmax ) {
                if(bmax > amax) amax = bmax;
                bmax = da;
            }
        }
        else {
            if ( db > bmax) {
                if(bmax > amax ) amax = bmax;
                bmax = db;
            }
            else if ( db > amax ) {
                if(amax > bmax) bmax = amax;
                amax = db;
            }
        }

        cout<< da << "\t" << db << "\t"<<temp<<"\t"<< dist-amax-bmax<<endl;
        cout<<amax<< "  " << bmax<<endl;

    }

    cout<<dist<<endl;

    dist -= (amax+bmax);

    cout<<fixed<<setprecision(10)<<dist<<endl;
}
