#include<stdio.h>

#define mx 100002
int arr[mx];
int tree[mx*3];

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

    tree[node] = tree[left] + tree[right];
    return;
}

int query(int node, int b, int e, int i, int j)
{
    //non-relevent
    if( j<b || i>e ) return 0;
    // relevent
    if( b>=i && e<=j ) return tree[node];

    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return p1+p2;
}

void update(int node, int b, int e, int i, int val)
{
    if( i>e || i<b) return;
    if(b>=i && e<=i)
    {
        tree[node] += val;
        return;
    }

    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;

    update(left, b, mid, i, val);
    update(right, mid+1, e, i, val);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/

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
            int type, j;
            scanf("%d", &type);

            if(type == 1)
            {
                int before = tree[1];
                scanf("%d", &j);

                update(1,1,n, j+1, -arr[j+1]);
                arr[j+1] = 0;

                printf("%d\n", before - tree[1]);
            }
            else if(type==2)
            {
                scanf("%d%d",&i, &j);
                update(1,1,n, i+1, j);
                arr[i+1] += j;
            }
            else
            {
                scanf("%d%d", &i, &j);
                printf("%d\n", query(1,1,n, i+1, j+1));
            }
        }
    }
    return 0;
}

