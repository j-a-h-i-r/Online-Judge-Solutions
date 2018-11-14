#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int r, sum = 0, low = -1;
        scanf("%d", &r);
        int house[r];

        for(int i = 0; i<r; i++){
            scanf("%d", &house[i]);
        }
        sort(house, house+r);

        int m = 0, n = 0;
        if(r%2==1) m = (r-1)/2;
        else {
            m = (r/2)-1;
            n = (r/2);
        }
        //cout<<m<<"  "<<n<<"  "<<house[m]<<endl;
        if(n==0) {
            for(int i=0; i<r; i++) {
                sum += abs(house[i]-house[m]);
                //cout<<sum<<" ";
            }
            printf("%d\n", sum);
        }
        else{
            for(int i = house[m]; i<=house[n]; i++){
                for(int j = 0; j<r; j++) sum+=abs(house[j]-i);

                if(sum<low || low == -1) low = sum;
                sum = 0;
            }
            printf("%d\n", low);
        }

    }
    return 0;
}

