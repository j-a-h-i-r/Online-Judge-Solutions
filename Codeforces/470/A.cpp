#include<iostream>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    int r, c;
    cin>>r>>c;
    char a[r][c];

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin>>a[i][j];
            if (a[i][j]=='.') a[i][j] = 'D';
        }
    }

    bool impossible = false;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (a[i][j] != 'W') continue;
            //cout<<">> "<<i<<" "<<j<<endl;
            for (int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x>=0 && x<r && y>=0 && y<c) {
                    if (a[x][y]=='S') {
                        impossible = true;
                        break;
                    }
                }
            }
        }
    }

    if (impossible) cout<<"No";
    else {
        cout<<"Yes\n";
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
