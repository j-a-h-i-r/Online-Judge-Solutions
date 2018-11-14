#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(st.empty() || st.top() != s[i] )
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }

        if(st.empty()) cout<<-1<<endl;
        else
        {
            stack<char>q;

            while( !st.empty() )
            {
                q.push(st.top());
                st.pop();
            }
            while(!q.empty())
            {
                cout<<q.top();
                q.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}
