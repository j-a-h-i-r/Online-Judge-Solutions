#include<bits/stdc++.h>
using namespace std;

char col[100002];

queue<int> qt, qf;  // false colored and true colored element gula save kore rakhar jonno

int cf = 0, ct = 0;  // false color, true color

int bipar( vector<int> g[] , int n )
{
    int bi = 1;  // jodi bipartite banaite pari. taile possible vertex cover paoa

    memset(col, '2' , sizeof col);
    //memset(vis, false , sizeof vis);

    queue <int> q;

    for(int i = 1; i <= n; i++) {
        //printf("i = %d\n", i);

        if( g[i].empty() ) continue;        // eitar kono edge nai , baad

        if( col[i] != '2' ) continue;       // eita already ekbar ghure aschi. so eitar sob neighbour ghura sesh, baad

       // printf("%d\n", i);

        q.push(i);
        col[i] = '1';
        ct++;
        qt.push(i);

        int flag = 1;

        while( !q.empty()  ) {

            int node = q.front(); q.pop();

            for(int j=0; j < g[node].size(); j++ )
            {
                if(col[ g[node][j] ] == '2' )
                {
                    q.push( g[node][j] );

                    if( col[node] == '1' ) {
                            col[ g[node][j] ] = '0';
                            cf++;
                            qf.push( g[node][j] );
                    }
                    else {
                        col [ g[node][j] ] = '1';
                        ct++;
                        qt.push( g[node][j] );
                    }
                }

                else if ( col[ g[node][j] ] == col[node] ) {
                    // bipartite hobe na
                    flag = 0;
                    break;
                }
            }
        }

        bi = bi & flag;
    }

    return bi;
}

int main()
{
    //freopen("in.txt","r", stdin);

    int n,m;
    scanf("%d%d" , &n, &m);

    vector <int> vec[n + 1 ];

    int u,v;

    for(int i=0; i<m; i++) {
        scanf("%d%d", &u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    int fl = bipar( vec, n );

    //printf("sdafas");


    if (fl == 0) {
        printf("-1\n");
    }
    else {

        printf("%d\n", ct);
        printf("%d", qt.front()); qt.pop();
        while(--ct) {
            printf(" %d", qt.front());
            qt.pop();
        }
        printf("\n");

        printf("%d\n", cf);
        printf("%d", qf.front()); qf.pop();
        while(--cf)
        {
            printf(" %d", qf.front());
            qf.pop();
        }
        printf("\n");
    }
}
