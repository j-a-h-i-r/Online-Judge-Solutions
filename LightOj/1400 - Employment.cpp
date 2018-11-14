#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, cs=0;
    int n;
    cin>>t;
    while(t--) {
        cin>>n;
        int emp[n+1], com[2*n+1];
        int empPre[n+1][n+1], comPre[2*n+1][n+1];
        for(int i=1; i<=n; i++) {
            for(int j=0; j<n; j++) cin>>empPre[i][j];
        }
        for(int i=n+1; i<=2*n; i++) {
            for(int j=0; j<n; j++) cin>>comPre[i][j];
        }

        queue<int> qe;

        for(int i=1; i<=n; i++) qe.push(i), emp[i]=-1, com[n+i]=-1;

        int x;

        while(!qe.empty()) {

            x = qe.front(); qe.pop();
            // X   is the  employee looking for a company

            for(int i=0; i<n; i++) {

                int z = empPre[x][i]; // x's preffered company

                // if the employee x's preffered company is free
                if( com[ z ] == -1) {
                    // match x with this company
                    // so company is not free
                    // it's matched with x
                    com[ z ] = x;
                    emp[x] = z;
                    break;
                }
                else {
                    // x's preffered company already has an employee
                    // let's see if they prefer x more than their current worker
                    int y = com[z];
                    bool flag = false;
                    // y is the current worker
                    for(int j=0; comPre[z][j] != y; j++) {
                        // loop till z's current worker

                        if( comPre[z][j] == x ) {
                            // x is more preffered
                            // make x paired
                            com[z] = x;
                            emp[x] = z;
                            // make y free
                            emp[y] = -1;
                            // push him into queue
                            qe.push(y);
                            //cout<<y<<endl;
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
            }
        }

        cout<<"Case "<<++cs<<":";
        for(int i=1; i<=n; i++) {
            cout<<" ("<<i<<" "<<emp[i]<<")";
        }
        cout<<"\n";
    }
    return 0;
}
