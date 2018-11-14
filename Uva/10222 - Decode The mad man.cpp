#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string s1 = "qwertyuiop[]\\";
    string s2="asdfghjkl;'";
    string s3 = "zxcvbnm,./";
    string s4 = "1234567890-=";
    unsigned int p;

    string s;
    while(cin>>s)
    {
        for(int i=0; i<s.length();i++)
        {
            s[i] = tolower(s[i]);
            if(s1.find(s[i])!=string::npos)
            {
                cout<<s1[ s1.find(s[i]) - 2 ];
            }
            else if(s2.find(s[i])!=string::npos)
            {
                cout<<s2[ s2.find(s[i]) - 2 ];
            }
            else if(s3.find(s[i])!=string::npos)
            {
                cout<<s3[ s3.find(s[i]) - 2 ];
            }
            else if(s4.find(s[i])!=string::npos)
            {
                cout<<s4[ s4.find(s[i]) - 2 ];
            }
        }
        char c = getchar();
        cout<<c;
    }
    return 0;
}
