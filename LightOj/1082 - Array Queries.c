#include<stdio.h>
#include<limits.h>

#define mx 100002
int arr[mx];
int tree[mx*3];

int min(int x, int y)
{
    return (x<y)? x : y;
}

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;

    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = min(tree[left], tree[right]);
    return;
}

int query(int node, int b, int e, int i, int j)
{
    //non-relevent
    if( j<b || i>e ) return INT_MAX;
    // relevent
    if( b>=i && e<=j ) return tree[node];

    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return min(p1, p2);
}

int main()
{
    int n, i, t, q, cs=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &q);
        for(i=1; i<=n; i++) scanf("%d", &arr[i]);

        init(1,1,n);

        printf("Case %d:\n", ++cs);

        while(q--)
        {
            int b,e;
            scanf("%d%d", &b, &e);
            printf("%d\n", query(1,1,n,b,e));
        }
    }
    return 0;
}

