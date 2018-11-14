#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    while(cin>>t) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> p;
        bool is_s = true;
        bool is_q = true;
        bool is_p = true;

        int counter = 0;

        int n, x;
        for (int i=0; i<t; i++) {
            cin>>n>>x;
            if (n==1) {
                s.push(x);
                q.push(x);
                p.push(x);

                counter++;
            }
            else {
                if (counter <= 0) {
                    is_s = false;
                    is_q = false;
                    is_p = false;
                    continue;
                }
                if (x != q.front()) is_q = false;
                if (x != s.top()) is_s = false;
                if (x != p.top()) is_p = false;

                s.pop();
                q.pop();
                p.pop();

                counter--;
            }
        }

        if (is_s && !is_q && !is_p) {
            cout<<"stack\n";
        }
        else if (is_q && !is_s && !is_p) {
            cout<<"queue\n";
        }
        else if (is_p && !is_q && !is_s) {
            cout<<"priority queue\n";
        }
        else if (!is_s && !is_q && !is_p) {
            cout<<"impossible\n";
        }
        else {
            cout<<"not sure\n";
        }
    }
    return 0;
}
