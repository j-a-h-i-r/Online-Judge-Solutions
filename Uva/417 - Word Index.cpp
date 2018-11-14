#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    static int m[23][24][25][26][27];

    int pos[5] = {0,0,0,0,0}, cur = 4, val=0;
    while(pos[0] <= 22)
    {
        m[pos[0]][pos[1]][pos[2]][pos[3]][pos[4]] = val++;
        pos[cur]++;
        while( pos[cur] > 26 - (4-cur) && cur > 0 )
        {
            // increase left by 1
            pos[cur-1]++;
            pos[cur] = pos[cur-1] + 1;
            // change all right
            for(int j = cur+1; j<5; j++) pos[j] = pos[j-1]+1;
            cur--;
        }
        cur = 4;
    }

    string s;
    while(cin>>s) {
        pos[0]=0;pos[1]=0;pos[2]=0;pos[3]=0;pos[4]=0;
        int i;
        for(i = 0 ; i < s.length() ; i++) {
            pos[5-s.length() + i] = s[i] - 'a' + 1;
        }
        cout<<m[pos[0]][pos[1]][pos[2]][pos[3]][pos[4]]<<endl;
    }
    return 0;
}
