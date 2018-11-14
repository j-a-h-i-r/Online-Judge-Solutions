#include<bits/stdc++.h>
#define maxx 100
using namespace std;
int main()
{
    int i,j,k,l,t,g[maxx][maxx],color[maxx],p,v,d[maxx];
    string s1,s2,d1,d2,a[maxx];
    map<string,int>mp;
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>t)
    {
        int c=0;
        memset(g,0,maxx*maxx*sizeof(g[0][0]));
        memset(color,0,sizeof(color));
        memset(d,-1,sizeof(d));
        for(i=0; i<t; i++)
        {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
            {
                a[c]=s1;
                mp[s1]=c++;

            }
            if(mp.find(s2)==mp.end())
            {
                a[c]=s2;
                mp[s2]=c++;
            }
            g[mp[s1]][mp[s2]]=1;
            g[mp[s2]][mp[s1]]=1;

        }


        cin>>d1>>d2;
        int u,des;
        queue<int>q,q1;
        p=mp[d1];
        des=mp[d2];

        color[p]=1;
        d[p]=0;
        q.push(p);

        while(!q.empty())
        {
            u=q.front();

            q.pop();
            for(v=0; v<c; v++)
            {
                if(g[u][v]==1)
                {
                    if(color[v]==0)
                    {
                        color[v]=1;
                        d[v]=d[u]+1;
                        q.push(v);

                        q1.push(u);
                        q1.push(v);

                    }
                }
            }


            color[u]=2;
        }

        if(d[des]>=0)
        {
             while(!q1.empty())
        {
            u=q1.front();
            q1.pop();
            v=q1.front();

            cout<<a[u]<<" "<<a[v]<<endl;
            q1.pop();
        }
        }
        else{
                cout<<"No route"<<endl;
            while(!q1.empty())
            {
                q1.pop();
            }
        }
        cout<<endl;
        mp.clear();
    }
    return 0;
}
