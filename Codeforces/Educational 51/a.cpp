#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--) {
        cin>>s;
        int l=0, u=0, d=0;

        for (int i=0; i<s.length; l++) {
            if (s[i]>='a' && s[i]<='z') l=1;
            else if (s[i]>='A' && s[i]<='Z') u=1;
            else d=1;
        }

        if (l>0 && u>0 && d>0) {
            cout<<s<<"\n";
        }
        else if (l+u+d == 2) {

        }
        else {
            if (l>s)
        }
    }
}
