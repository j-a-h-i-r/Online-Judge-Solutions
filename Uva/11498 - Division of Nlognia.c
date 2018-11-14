#include<stdio.h>
int main()
{
    int t;
    while((scanf("%d", &t)) && t!=0) {
        int n,m;
        scanf("%d%d", &n, &m);
        while(t--) {
            int x, y;
            scanf("%d%d", &x, &y);
            if(x==n || y==m) printf("divisa\n");
            else if(x>n && y>m) printf("NE\n");
            else if(x>n && y<m) printf("SE\n");
            else if(x<n && y>m) printf("NO\n");
            else if(x<n && y<m) printf("SO\n");
        }
    }
    return 0;
}
