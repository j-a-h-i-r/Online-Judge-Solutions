#include<iostream>
#include<cmath>
#include<cstdio>

long long power(long long x, long long n)
{
    if(n==0) return 1;
    long long k = power(x, n/2);
    if(n%2==0) {
        return k*k;
    }
    return x*k*k;
}

using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    long long int n;
    string s;
    cin>>n>>s;
    int i = s.length() - 1;
    int nz = i;

    long long int k = 0, num = 0, p=0, ten=1;
    bool lz = false;

    while(i>=0) {
        if(s[i]=='0' && ten<n) {
            if( ten!=1  ) lz = true;
            ten = ten*10;
            i--;
        }
        else if( s[i]!='0'&&k + ten*(s[i]-'0') < n ) {
            // take it
            //cout<<s[i]<<" "<<k<<" "<<ten<<endl;
            if(s[i]!='0') lz = false;
            k = k + (s[i]-'0')*ten;
            //cout<<i<<" "<<k<<endl;
            nz = i;
            i--;
            ten = ten*10;
        }
        else {
            // got k;
            //cout<<"full "<<k<<" "<<ten<<endl;
            if(lz==true) {
                // i have a left zero
                //i++;
                i = nz-1;
                nz = nz-1;
            }
            lz = false;
            num += k*power(n, p);
            p++;
            k = 0;
            ten = 1;
        }
    }
    //cout<<"out "<<k<<endl;
    //cout<<num<<endl;
    //cout<<k*pow(n,p)<<endl;
    if(k!=0) num = num + k*power(n,p);
    cout<<num;

}
