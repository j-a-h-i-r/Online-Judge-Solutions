#include<iostream>
#include<sstream>
#include<deque>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);

    int t, cs=0;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<++cs<<":"<<"\n";

        deque<int> dq;
        int n,m, tot=0;
        string inp, com;
        int num;
        stringstream ss;

        cin>>n>>m;
        cin.clear();
        cin.ignore(100, '\n');
        while(m--)
        {
            //cin.ignore(100, '\n');
            getline(cin, inp);

            //cout<<inp<<endl;
            ss.clear();
            ss.str(inp);

            //cout<<ss.str()<<endl;

            ss>>com;

            //cout<<com<<endl;

            if(com=="pushLeft")
            {
                ss>>num;
                if( tot < n )
                {
                    dq.push_front(num);
                    cout<<"Pushed in left: "<<num<<"\n";
                    tot++;
                }
                else
                {
                    cout<<"The queue is full\n";
                }
            }
            else if(com=="pushRight")
            {
                ss>>num;
                if( tot < n )
                {
                    dq.push_back(num);
                    cout<<"Pushed in right: "<<num<<"\n";
                    tot++;
                }
                else
                {
                    cout<<"The queue is full\n";
                }
            }
            else if(com=="popLeft")
            {
                if( !dq.empty() )
                {
                    cout<<"Popped from left: "<<dq.front()<<"\n";
                    dq.pop_front();
                    tot--;
                }
                else {
                    cout<<"The queue is empty\n";
                }
            }
            else if(com=="popRight")
            {
                if( !dq.empty() )
                {
                    cout<<"Popped from right: "<<dq.back()<<"\n";
                    dq.pop_back();
                    tot--;
                }
                else {
                    cout<<"The queue is empty\n";
                }
            }
        }
    }
    return 0;
}
