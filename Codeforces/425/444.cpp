#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

string decode(string str)
{
    string ret = "";
    int len = str.length();

    for (int i=0; i<len; i+=2) {
        int ascii = (str[i]-'0')*10 + (str[i+1]-'0');
        if (ascii < 30) {
            // get one more char
            ascii = ascii*10 + (str[i+2]-'0');
            i++;
        }
        ret += char(ascii);
    }
    return ret;
}
string int_to_string(int x)
{
    string ret = "";
    while(x!=0) {
        ret += (x%10) + '0';
        x /= 10;
    }
    return ret;
}
string encode(string str)
{
    string ret = "";
    int len = str.length();

    for (int i=0; i<len; i++) {
        int ascii = int(str[i]);
        ret += int_to_string(ascii);
    }
    return ret;
}

int main()
{
    string input;
    while( getline(cin, input) ) {
        reverse(input.begin(), input.end());
        if (input[0]>='0' && input[0]<='9') {
            cout<<decode(input)<<endl;
        }
        else cout<<encode(input)<<endl;
    }
    return 0;
}
