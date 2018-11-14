#include<stdio.h>

#define mx 100002
int tree[mx*2];

void build(int n) // building the tree. change assignation as necessary
{
    int i;
    for(i=n-1; i>0; --i) tree[i] = tree[2*i] + tree[2*i +1];
}

void update(int p, int val, int n) // update single array entry
{
    for(tree[p+=n] = val; p>1; p>>=1) tree[p>>1]=tree[p]+tree[p^1];
}

int query(int l, int r, int n)  // return query for a range of values
{
    int res=0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
        if(l&1) res+=tree[l++];
        if(r&1) res+=tree[--r];
    }
    return res;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i=1; i<=n; ++i) scanf("%d", tree+n+i);
    build(n);
    printf("%d\n", query(1,n+1, n));
    update(3,2, n);
    printf("%d\n", query(1,n+1, n));
    return 0;
}
