#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int n, p, cs = 0;
    bool line = false;
    while(cin>>n>>p)
    {
        getchar();
        //cout<<n<<" "<<p<<endl;
        if(n==0 && p==0) break;
        string discard;
        vector<string> name(p);
        vector<double> price(p);
        vector<int> req(p);
        while(n--) {
            getline(cin, discard);
            //cout<<discard<<"\n";
        }

        string inp;
        double pr;
        int rq;
        while(p--)
        {
            getline(cin, inp);
            //cout<<inp<<"\n";
            name.push_back(inp);
            cin>>pr>>rq;
            getchar();
            price.push_back(pr);
            req.push_back(rq);
            while(rq--) getline(cin, discard);
        }
        int idx = 0;
        for(int i=1; i<name.size(); i++ )
        {
            if( req[i] > req[idx] ) {
                idx = i;
            }
            else if( req[i] == req[idx] )
            {
                if( price[i] < price[idx] ) idx = i;
            }
        }
        if(line) cout<<"\n"; line = true;
        cout<<"RFP #"<<++cs<<"\n";
        cout<<name[idx]<<"\n";
    }
    return 0;
}
