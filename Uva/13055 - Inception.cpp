#include<iostream>
#include<sstream>
#include<stack>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    stringstream ss;
    string com, name, inp;
    stack<string> nameStack;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        ss.clear();
        ss.str("");
        getline(cin, inp);

        ss<<inp;
        //cout<<"ss "<<ss.str()<<"\n";
        ss>>com;
        //cout<<com<<"\n";

        if( com=="Sleep" ) {
            ss>>name;
            //cout<<name<<"\n";
            nameStack.push(name);
        }
        else if(com=="Kick") {
            //cout<<"kk\n";
            if( !nameStack.empty() ) nameStack.pop();
        }
        else if(com=="Test") {
            //cout<<"sfa\n";
            if(!nameStack.empty() )
            {
                cout<<nameStack.top()<<"\n";
                //nameStack.pop();
            }
            else cout<<"Not in a dream\n";
        }
    }
    return 0;
}
