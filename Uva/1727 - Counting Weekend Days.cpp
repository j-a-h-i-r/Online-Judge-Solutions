#include<iostream>
#include<map>
#include<cstdio>
using namespace std;

int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/

    map<string,int> mnt;
    mnt["JAN"] = 31;
    mnt["FEB"] = 28;
    mnt["MAR"] = 31;
    mnt["APR"] = 30;
    mnt["MAY"] = 31;
    mnt["JUN"] = 30;
    mnt["JUL"] = 31;
    mnt["AUG"] = 31;
    mnt["SEP"] = 30;
    mnt["OCT"] = 31;
    mnt["NOV"] = 30;
    mnt["DEC"] = 31;

    map<string, int> day;
    day["SUN"] = 0;
    day["MON"] = 1;
    day["TUE"] = 2;
    day["WED"] = 3;
    day["THU"] = 4;
    day["FRI"] = 5;
    day["SAT"] = 6;

    int n;
    cin>>n;
    //cin.clear();
    //cout<<n<<endl;
    while(n--)
    {
        string m, d;
        cin>>m>>d;
        //cout<<m<<" "<<d<<endl;

        int totDay = mnt[m];

        int fridayDate = 1 + day["FRI"] - day[d];
        int possibleWeekday = 2;
        if( fridayDate == 0 ) possibleWeekday = 1;
        fridayDate += 7;
        while(fridayDate <= totDay )
        {
            possibleWeekday += 2;
            if( fridayDate+1 > totDay ) possibleWeekday--;
            fridayDate += 7;
        }
        cout<<possibleWeekday<<endl;
    }
    return 0;
}
