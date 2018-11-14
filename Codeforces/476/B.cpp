#include<iostream>
#include<cstdio>
using namespace std;
int n, k, curmax;
int find_max(char b[100][100], int x, int y) {

    // left k steps
    int l = max(y-k+1, 0);
    for (int i=y; i>=0; --i) {
        if (y-i+1 > k ) break;
        if (b[x][i] == '#') {
            l = i+1;
            break;
        }
    }
    int countl = 0;
    for (int i=y; i<n; i++) {
        if (i-k+1 > y) break;
        if (b[x][i] == '#') break;
        //countl++;
        if (i-l+1 == k) {
            countl++;
            l++;
        }
    }

    // up k steps ;
    int u = max(x-k+1, 0);
    for (int i=x; i>=0 ; --i) {
        if (x-i+1 > k) break;
        if (b[i][y] == '#') {
            u = i+1;
            break;
        }
    }
    int countu = 0;
    for (int i=x; i<n; i++) {
        if (i-k+1 > x) break;
        if (b[i][y] == '#') break;

        if (i-u+1 == k) {
            countu++;
            u++;
        }
    }
    //cout<<x+1<<" "<<y+1<<" "<<countl<<" "<<countu<<endl;
    return countl + countu;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    curmax = -1;

    cin>>n>>k;
    char board[100][100];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>board[i][j];
        }
    }
    int r, c;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(board[i][j] == '#') continue;
            int t = find_max(board, i, j);
            if ( t > curmax ) {
                r = i;
                c = j;

                curmax = t;
                //cout<<r+1<<" "<<c+1<<" "<<curmax<<endl;
            }
        }
    }
    cout<<r+1<<" "<<c+1;
}
