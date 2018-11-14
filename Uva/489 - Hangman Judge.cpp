#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    while(cin>>n)
    {
        if(n==-1) break;
        string ans, guess;
        cin>>ans>>guess;
        map<char, int> mp, stg, stw;
        for(int i=0; i<26; i++) {
            mp[ char(i+'a') ] = -1;
        }

        int corr=0, wrong=0, corrchar = 0;

        for(int i=0; i<ans.length(); i++) {
            if( mp[ans[i]] == -1 ) corrchar++;
            mp[ans[i]] = 0;
        }
        for(int i=0; i<guess.length(); i++) {
            char c = guess[i];
            if( mp[c]==-1 ) {
                wrong++;
                mp[c] = -2;
            }
            else if(mp[c]==0) {
                corr++;
                mp[c] = 1;
            }
            if(corr==corrchar) {
                cout<<"Round "<<n<<"\n";
                cout<<"You win.\n";
                break;
            }
            else if( wrong==7 ) {
                cout<<"Round "<<n<<"\n";
                cout<<"You lose.\n";
                break;
            }
        }
        if( corr<corrchar && wrong<7 ) {
            cout<<"Round "<<n<<"\n";
            cout<<"You chickened out.\n";
        }
    }
    return 0;
}
