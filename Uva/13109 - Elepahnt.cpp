#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        long m,w;
        scanf("%ld%ld", &m, &w);

        int a[m];

        for(int i = 0; i<m; i++) scanf("%d", &a[i]);

        sort(a, a+m);

       /* for(int i = 0; i<m; i++) printf("%d ", a[i]);
        printf("\n");*/

        long sum = 0;
        long c=0;

        for(int i = 0; i<m; i++) {
            if(sum + a[i] <= w) {
                sum = sum + a[i];
                c++;
            }
            else break;
        }

        printf("%ld\n", c);
    }

    return 0;
}
