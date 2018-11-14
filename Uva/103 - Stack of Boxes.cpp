#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<stack>
using namespace std;

bool comp(vector<int>a, vector<int> b)
{
    for(int i=1; i<a.size(); i++)
    {
        if( a[i] < b[i] ) return true;
        else if (a[i] > b[i]) return false;
    }
}

bool takeAble(vector<int> a, vector<int> b)
{
    for(int i = 1; i<a.size(); i++)
    {
        if(a[i] >= b[i]) return false;
    }
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out1.txt", "w", stdout);

    int n, k, d;
    while( cin>>n>>k )
    {
        vector< vector<int> > boxes(n);

        for(int i=0; i<n; i++)
        {
            boxes[i].push_back(i+1);
            for(int j=0; j<k; j++)
            {
                cin>>d;
                boxes[i].push_back(d);
            }
            sort(++boxes[i].begin(), boxes[i].end());
        }
        sort(boxes.begin(), boxes.end(), comp);

        vector<int> L(n, 1);

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if( takeAble(boxes[i], boxes[j]) )
                {
                    if( L[j] < 1 + L[i] ) L[j] = 1 + L[i];
                }
            }
        }

        int lcs = 1, lastPos = 0;
        for(int i=1; i<n; i++)
        {
            if(L[i] > L[lastPos] )
            {
                lcs = L[i];
                lastPos = i;
            }
        }

        vector<int> boxSeq(lcs);
        int top = lcs - 1;
        boxSeq[top--] = boxes[lastPos][0];

        for(int j = lastPos-1; j>=0; j-- )
        {
            if( takeAble(boxes[j], boxes[lastPos]) && (L[j] == L[lastPos] - 1) )
            {
                lastPos = j;
                boxSeq[top--] = boxes[j][0];
            }
        }

        cout<<lcs<<endl;
        cout<<boxSeq[0];
        for(int i=1; i<lcs; i++) cout<<" "<<boxSeq[i];
        cout<<endl;
    }
    return 0;
}
