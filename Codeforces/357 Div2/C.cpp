#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<sstream>

#define ll long long

using namespace std;

int main()
{
    freopen("in.txt","r", stdin);

    priority_queue<ll> q;
    vector<string> v;
    string str;
    stringstream sstm;

    int t, c = 0;
    cin>>t;

    while(t--)
    {
        char s[10];
        ll n = 1;
        cin>>s;
        if(s[0] != 'r') cin>>n;

        cout<<s<< "  " << n<<endl;


        if(s[0] = 'i') {
            q.push(n);

            sstm<<"insert "<< n;
            str = sstm.str();
            v.push_back(str);

            c++;
        }

        else if(s[0] == 'g'){
            if( q.empty() ) {
                // i have to insert n
                q.push(n);

                sstm<<"insert " << n;
                str = sstm.str();
                v.push_back(str);
                sstm<<"getMin "<< n;
                str = sstm.str();
                v.push_back(str);

                c+=2;
            }

            else if( n==q.top() ) {
                // top mile geche
                // so eitate kono jhamela nai
                sstm<<"getMin "<< n;
                str = sstm.str();
                v.push_back(str);

                c++;
            }

            else {
                // min eita na;
                while(q.top() < n ) {
                    q.pop();

                    sstm<<"removeMin"<< n;
                    str = sstm.str();
                    v.push_back(str);
                    c++;
                }

                if(q.top() != n) {
                    q.push(n);

                    sstm<<"insert "<< n;
                    str = sstm.str();
                    v.push_back(str);
                    sstm<<"getMin "<< n;
                    str = sstm.str();
                    v.push_back(str);
                    c+=2;
                }

                else {
                    sstm<<"getMin "<< n;
                    str = sstm.str();
                    v.push_back(str);
                    c++;
                }
            }
        }

        else if(s[0] == 'r')
        {
            // get minimum element
            if(q.empty()) {
                // insert
                q.push(1);
                q.pop();

                sstm<<"insert "<< 1;
                str = sstm.str();
                v.push_back(str);
                sstm<<"removeMin";
                str = sstm.str();
                v.push_back(str);

                c+=2;
            }
            else {
                q.pop();
                sstm<<"removeMin";
                str = sstm.str();
                v.push_back(str);
                c++;
            }
        }
    }

    cout<<v.size()<<endl;

    vector<string>::iterator it;

    for(it = v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<endl;
    }
}
