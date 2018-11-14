#include<stdio.h>

static int row[100001];
static int col[100001];

int main()
{
    long long  n, m;
    scanf("%I64d%I64d",&n,&m);

    long long un = n*n, at, r=0,c=0;

    int i,j;

    for(i=1; i<=m; i++)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        at = 0;
        if(row[x]==0)
        {
            at = n - c;
            row[x] = 1;
            r++;
        }
        if(col[y]==0)
        {
            at += n - r;
            col[y] = 1;
            c++;
        }

        //printf("at = %lld\n", at);

        un -= (at);

        printf("%I64d ", un);
    }
    return 0;
}
