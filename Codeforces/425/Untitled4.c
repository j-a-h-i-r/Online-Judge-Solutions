#include<vector>
#include<iostream>
using namespace std;


vector<int> encode(string st)
{
    vector<int>v;
    for(int i=st.length()-1;i>=0;i--)
    {
        int value=(int)st[i];
        if(isspace(st[i]))value=32;
        if(value>=100)
        {
            while(value>0)
            {
                v.push_back(value%10);
                value=value/10;
            }
        }
        else
        {
            v.push_back(value%10);
            v.push_back(value/10);
        }
    }
    return v;
}

vector<char> decode(string st)
{
    vector<char>v;
    int number=0;
    for(int i=st.length()-1;i>=0;i--)
    {
        if(st[i]!='1')
        {
            number=((st[i]-'0')*10)+(st[i-1]-'0');
            i--;
        }
        if(st[i]=='1')
        {
            number=((st[i]-'0')*100)+((st[i-1]-'0')*10)+(st[i-2]-'0');
            i=i-2;
        }
        v.push_back((char)number);
        number=0;
    }
    return v;
}

int main()
{
    vector<int>v;
    vector<char>ch;
    string st;
    while(getline(cin,st))
    {
        if(isdigit(st[0]))
        {
            ch=decode(st);
            for(int i=0;i<ch.size();i++) cout<<ch[i];
        }
        else
        {
            v=encode(st);
            for(int i=0;i<v.size();i++)cout<<v[i];
        }
        cout<<endl;
    }
    return 0;
}
