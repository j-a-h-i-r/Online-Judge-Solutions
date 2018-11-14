#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> v;
    vector<string> song;

    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("Rujia");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");

    string s;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        v.push_back(s);
    }
    int k = max(n, 16);

    if(k%16 != 0 )
    {
        k = ((k/16)+1)*16;
    }

    int x = 0, i=0, j=0;

    while(x < k )
    {
        cout<<v[i++]<<": "<<song[j++]<<"\n";
        i = i%n;
        j = j%16;
        x++;
    }
}
