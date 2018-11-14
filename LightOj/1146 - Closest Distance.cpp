#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

const double EPS = 1e-15;

double ax,ay,bx,by,cx,cy,dx,dy;

double dis(double k)
{
    double px,py,qx,qy;
    px = (1.0-k)*ax + k*bx;
    py = (1.0-k)*ay + k*by;
    qx = (1.0-k)*cx + k*dx;
    qy = (1.0-k)*cy + k*dy;

    return sqrt( (px-qx)*(px-qx) + (py-qy)*(py-qy) );
}

int main()
{
    //freopen("in.txt","r",stdin);

    int t, cs = 0;
    cin>>t;
    while(t--)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;

        double u = 1.00, l=0.0;
        double m1, m2;

        int i=0;

        while(u-l>EPS && i<=300)
        {
            m1 = l + (u-l)/3.0;
            m2 = u - (u-l)/3.0;

            if(dis(m1)>dis(m2))
            {
                l=m1;
            }
            else u = m2;
            i++;
        }
        cout<<"Case "<<++cs<<": ";
        //cout<<l<<"  ";
        cout.precision(7);
        cout<<fixed<<dis(l)<<"\n";

    }
    return 0;
}
