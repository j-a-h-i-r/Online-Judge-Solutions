#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);

    stack<char> q;
    char c;

    while(scanf("%c", &c) != EOF)
    {
        printf("%c", c);
        q.push(c);
    }

    while(!q.empty())
    {
        printf("%c", q.top());
        q.pop();
    }
    return 0;
}
