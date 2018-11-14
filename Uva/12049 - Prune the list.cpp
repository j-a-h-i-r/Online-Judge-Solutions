#include<iostream>
#include<set>
#include<map>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        set<int> all;
        map<int,int> aMap;
        int m,n, elem,  tot = 0;
        cin>>m>>n;
        while(m--)
        {
            cin>>elem;
            all.insert(elem);
            if( aMap.find(elem) != aMap.end() )
            {
                aMap[elem]++;
            }
            else aMap[elem] = 1;
        }
        while(n--)
        {
            cin>>elem;
            all.insert(elem);
            if( aMap.find(elem) != aMap.end() )
            {
                aMap[elem]--;
            }
            else tot++;
        }
        set<int>::iterator it;
        for(it=all.begin(); it!=all.end(); ++it)
        {
            tot += abs(aMap[*it]);
        }

        cout<<tot<<endl;
    }
    return 0;
}
