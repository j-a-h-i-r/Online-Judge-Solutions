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
    freopen("in.txt","r",stdin);

    long long int n;
    string s;
    cin>>n>>s;
    int i = s.length() - 1;

    long long int k = 0, num = 0, p=0, ten=1;

    while(i>=0) {
        if(s[i]=='0') {
            // traverse left and check for \
            // first non-zero element
            // sum all intermediate nums and if the
            // sum is less than n then take it
            // else this 0 is single 0;
            int j=i;
            long long t = k, tn = ten;
            cout<<"k "<<k<<endl;
            while(j>=0) {
                if(s[j]!='0') break;
                tn=tn*10;
                j--;
            }
            //cout<<tn<<endl;
            t = tn*(s[j]-'0')+k;
            //cout<<"t "<<t<<endl;
            if( t < n) {
                // i can take all this
                //cout<<"taking "<<t<<" "<<p<<endl;
                num += t*power(n, p);
                p++;
                k = 0;
                ten = 1;
                i = j-1;
                //cout<<"i "<<i<<endl;
            }
            else {
                // i can't take this\
                // take single zero
                if(k!=0) {
                    num += k*power(n, p);
                    p++;
                    k = 0;
                    ten = 1;
                }
                else {
                    num += 0;
                    p++;
                    k = 0;
                    ten = 1;
                    i--;
                }
            }
        }
        else if( k + ten*(s[i]-'0') <= n ) {
            // take it
            k = k + (s[i]-'0')*ten;
            //cout<<i<<" "<<k<<endl;
            i--;
            ten = ten*10;
        }
        else {
            // got k;
            cout<<"full "<<k<<endl;
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
