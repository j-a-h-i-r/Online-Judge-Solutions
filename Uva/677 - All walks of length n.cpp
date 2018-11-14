#include<cstdio>
#include<iostream>
using namespace std;

bool taken[11][11], took[11];
int pos[10];
int adj[11][11];
bool flag = false, line = false;
int n, m;

void all_path( int node_num ) {
    if(node_num == m+1 ) {
        flag = true;

        cout<<"("<<pos[0];

        for(int i=1; i<node_num; i++) {
            cout<<","<<pos[i];
        }
        cout<<")\n";
        return;
    } else {
        int p = pos[node_num-1];
        for(int i=1; i<=n; i++) {
            if( adj[p][i]== 1 && taken[p][i] == false && took[i]==false ) {
                taken[p][i] = true;
                taken[i][p] = true;
                took[i] = true;

                pos[node_num] = i;
                all_path( node_num + 1 );

                taken[p][i] = false;
                taken[i][p] = false;
                took[i] = false;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int discard;
    while(cin>>discard) {
        if(discard == -9999) {
            // discard it
            // read n, m;
            cin>>n>>m;
        }
        else {
            n = discard;
            cin>>m;
        }

        //cout<<n<<" "<<m<<endl;

        for(int i=1; i<=n; i++) {
            took[i] = false;
            for(int j=1; j<=n; j++) {
                cin>>adj[i][j];
                taken[i][j] = false;
            }
        }

        if(line) cout<<"\n"; line = true;

        pos[0] = 1;
        took[1] = true;
        all_path( 1 );
        if(flag == false) {
            cout<<"no walk of length "<<m<<"\n";
        }
        flag = false;
    }

    return 0;
}

