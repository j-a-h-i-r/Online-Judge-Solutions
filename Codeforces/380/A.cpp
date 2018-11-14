#include<iostream>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        if( s[i]!='o' ) cout<<s[i];
        else
        {
            int j;
            bool fl = true, f=false;
            while(fl)
            {
                for(j=i+1; j<n; j+=2)
                {
                    if( s[j]=='g'&&s[j+1]=='o' ) f = true;
                    else {
                        fl = false;
                        break;
                    }
                }
                break;
                //cout<<i<<endl;
            }
            if(f) cout<<"***";
            if(f) i = j-1;
            if(!f) cout<<s[i];
            //cout<<endl<<i<<"\n";
        }
    }
    return 0;
}
