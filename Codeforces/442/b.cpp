#include<bits/stdc++.h>
using namespace std;

#define NOT_TAKEN -1
#define TAKEN 0
#define DONE 1

string s;
int len;

int f(int b_st, int cur, int tot)
{
    if ( cur == len ) return tot;

    if (s[cur] == 'a') {
        int m1=-1, m2=-1, m3=-1;
        if (b_st==TAKEN) {
            m1 = max( f(DONE, cur+1, tot+1), f(TAKEN, cur+1, tot));
        }
        else {
            m2 = max( f(b_st, cur+1, tot+1), f(b_st, cur+1, tot) );
        }

        return max(m1, m2);
    }
    else {
        int m1=-1, m2=-1, m3=-1;
        if (b_st==NOT_TAKEN) {
            m1 = max(f(TAKEN, cur+1, tot+1), f(NOT_TAKEN, cur+1, tot));
        }
        else if (b_st==TAKEN) {
            m2 = max(f(TAKEN, cur+1, tot+1), f(TAKEN, cur+1, tot));
        }
        else {
            m3 = f(DONE, cur+1, tot);
        }

        return max(m1, max(m2, m3));
    }
}


int main()
{
    //string s;
    cin>>s;

    len = s.length();

    cout<<f(NOT_TAKEN, 0, 0);

    return 0;
}
