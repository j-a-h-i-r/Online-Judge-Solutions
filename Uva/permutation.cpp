#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;
bool taken[100];

void generate(int idx)
{
    if(idx==n) {
        for(int i=0; i<idx; i++) cout<<v[i];
        cout<<"\n";
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(taken[i] == false)
        {
            taken[i] = true;
            v.push_back(i);
            generate(idx+1);
            taken[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    n = 7;
    for(int i=0; i<=n ; i++) taken[i] = false;
    vector<int> v;
    generate(0);
}
