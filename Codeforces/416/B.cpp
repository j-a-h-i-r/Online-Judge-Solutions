#include<cstdio>
using namespace std;

int main()
{
    int n, m, l, r, x, cnt;
    int a[10005];
    scanf("%d %d", &n, &m);

    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &l, &r, &x);
        //val = a[x-1];
        cnt = 0;
        for (int j=l-1; j<r; j++) {
            if ( a[j] < a[x-1] ) ++cnt;
        }

        if ( l + cnt == x ) {
            printf("Yes\n");
        }
        else printf("No\n");

    }
    return 0;
}
