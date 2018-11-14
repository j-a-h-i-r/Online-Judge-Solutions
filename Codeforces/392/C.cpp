#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);

    long long int n, m, k, x,y;
    long long mx=1, mn=1, sg=1;

    cin>>n>>m>>k>>x>>y;


    if( k / (n*m) == 0 ) {
        // sobaire question korte parbe na
        // at least ekjon ache jare kono question kora hoy nai
        // minmum is 0;
        mn = 0;
        // maximum is 1
        mx = 1;
        // lets find position of last student asked question
        // he is in (k/m) th row

        sg = 1;

        int r = (k-1)/m + 1;
        int c = k - ((r-1)*m);

        if(r<x) {
            sg = 0;
        }
        else if (r==x && c<y){
            sg = 0;
        }
    }
    else {
        // all the students have been asked at least 1 ques
        // set all to 1 and subtract the asked questions
        k -= (n*m);
        // lets' calculate total turns the whole class takes
        long long turn = k/ ( (n-1)*m*2 );
        // students in 1st and nth row gets 1 question per turn
        //    ""    "" 2nd and n-1 th row gets 2;

        // add turn to min
        // add 2*turn to max
        cout<<turn<<endl;

        mn += turn;
        mx += 2*turn;

        // calculate remaining questions

        k -= turn*( (n-1)*m*2 );

        // i've got the minimum
        // need to find the max and sergeis total ques
        if(k>0) {
            // still questions left
            mx = mx+1;

            // teacher have to ask q questions to reach sergei
            int q = (n-1-x)*m + (y-1);
            if(q>=0 && k >=q ) sg = sg+1;

            k -= (n-1)*m;

            if(k>0) {
                mx = mx+1;

                q = (x-2)*m + (y-1);
                if(q>=0 && k>=q ) sg = sg+1;
            }
        }
    }
    cout<<mx<<" "<<mn<<" "<<sg<<endl;

}
