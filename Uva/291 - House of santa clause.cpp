#include<cstdio>

#include<iostream>
using namespace std;

bool taken[6][6];
int pos[10];
int adj[6][6];
bool flag = false;

void show_all(int id) {
    if(id==9) {
        for(int i=0; i<id; i++) {
            cout<<pos[i];
        }
        cout<<"\n";
        return;
    } else {
        int p = pos[id-1];
        for(int i=1; i<6; i++) {
            if( adj[p][i]==true && taken[p][i] == false ) {
                taken[p][i] = true;
                taken[i][p] = true;

                pos[id] = i;
                show_all( id+1 );

                taken[p][i] = false;
                taken[i][p] = false;
            }
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);

    for(int i=0; i<=5; i++) {
        for(int j=0; j<=5; j++) {
            taken[i][j] = false;
            adj[i][j] = false;
        }
    }
    for(int i=0; i<10; i++) pos[i] = 0;

    adj[1][2] = true;adj[1][3] = true;adj[1][5] = true;
    adj[2][1] = true;adj[2][3] = true;adj[2][5] = true;
    adj[3][1] = true;adj[3][2] = true;adj[3][4] = true;adj[3][5] = true;
    adj[4][3] = true;adj[4][5] = true;
    adj[5][1] = true;adj[5][2] = true;adj[5][3] = true;adj[5][4] = true;

    pos[0] = 1;
    show_all( 1 );

    return 0;
}
