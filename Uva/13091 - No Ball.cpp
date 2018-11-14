#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);

    int t, cs=0;
    scanf("%d",&t);
    //getchar();
    while(t--)
    {
        int stamp, foot, dik;
        string field[5];
        for(int i=0; i<5; i++)
        {
            cin>>field[i];
            //cout<<field[i]<<"\n";
            for(int j=0; j<5; j++)
            {
                if(field[i][j]=='|') stamp = j;
                else if(field[i][j]=='>') {
                    foot = j;
                    dik = 1;
                }
                else if(field[i][j]=='<')
                {
                    foot = j;
                    dik = -1;
                }
            }
        }
        //cout<<stamp<<" "<<foot<<" "<<dik<<"\n";
        //getchar();
        //getchar();
        //getchar();
        //getchar();

        if( foot<stamp )
        {
            // pa stamp er baam e
            if(dik==1) cout<<"Case "<<++cs<<": Thik Ball\n";
            else cout<<"Case "<<++cs<<": No Ball\n";
        }
        else {
            // pa stamp er daan e
            if(dik==1) cout<<"Case "<<++cs<<": No Ball\n";
            else cout<<"Case "<<++cs<<": Thik Ball\n";
        }
    }
    return 0;
}
