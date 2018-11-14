#include<cstdio>
#include<algorithm>
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int a[n+2];

        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        std::sort(a, a+n);

        int sum = 0;

        for(int i=0; i<n-1; i++) {
            sum += (a[i+1] - a[i]);
        }

        printf("%d\n", 2*sum);
    }
    return 0;
}
