#include<stdio.h>
#include<limits.h>

#define mx 100002
int tree[mx*2];

int min(int x, int y)
{
    return (x<y)? x : y;
}

void build(int n)
{
    int i;
    for(i=n-1; i>0; --i) tree[i] = min(tree[2*i], tree[2*i +1]);
}

/*void update(int p, int val, int n)
{
    for(tree[p+=n] = val; p>1; p>>=1) tree[p>>1]=tree[p]+tree[p^1];
}*/

int query(int l, int r, int n)
{
    int res=INT_MAX;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
        if(l&1) res = min(res, tree[l++]);
        if(r&1) res = min(res, tree[--r]);
    }
    return res;
}

int main()
{
    int n, i, t, q, cs = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &q);
        for(i=1; i<=n; ++i) scanf("%d", tree+n+i);
        build(n);

        printf("Case %d:\n", ++cs);

        while(q--)
        {
            int b, e;
            scanf("%d%d", &b, &e);
            printf("%d\n", query(b,e+1, n));
        }
    }
    return 0;
}

